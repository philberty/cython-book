#ifndef __ASYNC_MESSAGE_SERVER_H__
#define __ASYNC_MESSAGE_SERVER_H__

typedef struct client {
  int fd;
  char * cid;
  struct bufferevent *buf_ev;
} client_t;

typedef int (*callback_t)(const client_t *, const char *);

extern void SetConnectCallback(callback_t);
extern void SetDisconnectCallback(callback_t);
extern void SetReadCallback(callback_t);

extern void StartServer(int port);
extern void StopServer();

#endif //__ASYNC_MESSAGE_SERVER_H__
