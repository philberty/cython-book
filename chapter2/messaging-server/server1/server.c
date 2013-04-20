#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>

#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

#include "server.h"
#include "signal.h"

static struct event_base *evbase;

int setnonblock (int fd)
{
  int flags;

  flags = fcntl (fd, F_GETFL);
  if (flags < 0)
    return flags;

  flags |= O_NONBLOCK;
  if (fcntl (fd, F_SETFL, flags) < 0)
    return -1;

  return 0;
}

void
callback_client_read (struct bufferevent *bev, void *arg)
{
  uint8_t data[8192];
  size_t n;

  for (n = bufferevent_read (bev, data, sizeof (data));
       n > 0;
       n = bufferevent_read (bev, data, sizeof (data))
       )
    {
      printf ("data = %s\n", data);
    }
}
void callback_client_error (struct bufferevent *bev, short what, void *arg)
{
  client_t *client = (struct client *) arg;
  if (what & BEV_EVENT_EOF)
    {
      /* Client disconnected, remove the read event and the
       * free the client structure. */
      printf ("Client disconnected %s.\n", client->cid);
    }
  else
    warn("Client socket error, disconnecting.\n");

  bufferevent_free(client->buf_ev);
  close(client->fd);
  free (client->cid);
  free(client);
}

void callback_client_connect (int fd, short ev, void *arg)
{
  int client_fd;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);

  client_fd = accept (fd, (struct sockaddr *)&client_addr,
		      &client_len);
  if (client_fd < 0)
    {
      warn ("accept failed");
      return;
    }

  /* Set the client socket to non-blocking mode. */
  if (setnonblock(client_fd) < 0)
    warn("failed to set client socket non-blocking");

  client_t * client = malloc (sizeof (struct client));
  memset (client, 0, sizeof (struct client));

  client->fd = client_fd;
  client->cid = strdup (inet_ntoa (client_addr.sin_addr));

  client->buf_ev = bufferevent_socket_new (evbase, client_fd, 0);
  bufferevent_setcb (client->buf_ev,
		     &callback_client_read,  // read event
		     NULL,                   // write event
		     &callback_client_error, // on error
		     client);                // argument
  bufferevent_enable (client->buf_ev, EV_READ);
}

void init_server (int port)
{
  int sockfd;
  struct sockaddr_in serv_addr;

  /* Initialize libevent. */
  evbase = event_base_new ();

  sockfd = socket (AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    {
      perror ("ERROR opening socket");
      exit (1);
    }

  memset (&serv_addr, 0, sizeof (serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons (port);

  // now bind to the address...
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
	   sizeof(serv_addr)) < 0)
    {
      perror ("ERROR on binding");
      exit (1);
    }
  // begin listening on socket...
  listen (sockfd, 5);

  int reuseaddr_on = 1;
  struct event ev_accept;
  setsockopt (sockfd,
	      SOL_SOCKET, SO_REUSEADDR,
	      &reuseaddr_on,
	      sizeof (reuseaddr_on));

  /* Set the socket to non-blocking, this is essential in event
   * based programming with libevent.
   */
  if (setnonblock (sockfd) < 0)
    {
      perror ("failed to set server socket to non-blocking");
      exit (1);
    }

  /* We now have a listening socket, we create a read event to
   * be notified when a client connects. */
  event_assign (&ev_accept, evbase,
		sockfd,
		EV_READ|EV_PERSIST,
		&callback_client_connect,
		NULL);
  event_add (&ev_accept, NULL);

  /* Start the event loop. */
  event_base_dispatch (evbase);
  event_base_free (evbase);
}

int main (int argc, char **argv)
{
  init_server (9080);
  return 0;
}
