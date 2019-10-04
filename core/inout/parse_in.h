#ifndef _PARSE_IN_H
#define _PARSE_IN_H
#include "../../config.h"

/*
Read the arguments passed on function start
*/
int read_args(int argc, char **argv, double* data);

/*
Read
*/
int read_input(double *data);

#ifdef DEBUG_PARSE_IN
# define PARSE_IN_DEBUG(a...)  printf("DEBUG_PARSE_IN: " a)
#else
# define PARSE_IN_DEBUG(a...)
#endif

#endif /* _PARSE_IN_H */
