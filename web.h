#include <curl/curl.h>
#include <gnutls/gnutls.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <zwalker.h>
#include <zmime.h>
#include "error.h"

#ifndef WEB_H
#define WEB_H

typedef struct wwwResponse {
	int status, len, clen, chunked;
	uint8_t *data, *body;
	char *redirect_uri;
	char ctype[ 1024 ];
	char err[ 1024 ];
	char ipv4[ INET6_ADDRSTRLEN ];
	char ipv6[ 1024 ];
} wwwResponse;

typedef struct stretchBuffer {
	int len;
	uint8_t *buf;
} Sbuffer;


int load_www ( const char *p, wwwResponse *r );
#ifdef DEBUG_H
void print_www ( wwwResponse *r ) {
#endif
#endif
