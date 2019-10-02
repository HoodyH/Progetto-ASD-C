#ifndef _PARSE_IN_H
#define _PARSE_IN_H
#include "../../config.h"

/*
Read the arguments passed on function start
*/
int read_args(int argc, char **argv);

/*
R
*/
int read_float_input(float *data);

#ifdef DEBUG_PARSE_IN
# define PARSE_IN_DEBUG(a...)  printf("TDBASE_PRO: " a)
#else
# define PARSE_IN_DEBUG(a...)
#endif

#endif /* _PARSE_IN_H */
