#ifndef __SERVER_H__
#define __SERVER_H__

typedef struct client {
  int fd;
  char * cid;
  struct bufferevent *buf_ev;
} client_t;

#endif //__SERVER_H_
