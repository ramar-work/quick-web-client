#include <stdio.h>

#ifndef ERROR_H
#define ERROR_H
int err_set ( int status, char *fmt, ... );
int err_print ( int status, char *fmt, ... );
extern int died;
#endif
