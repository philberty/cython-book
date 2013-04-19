#ifndef __SERVER_H__
#define __SERVER_H__

typedef struct client {
  int fd;
  char * cid;
  struct bufferevent *buf_ev;
} client_t;

typedef void (*callback)(client_t *, char *);

extern void setConnect_PyCallback (callback);
extern void setDisconnect_PyCallback (callback);
extern void setRead_PyCallback (callback);
extern void init_server (int);

#endif //__SERVER_H_
