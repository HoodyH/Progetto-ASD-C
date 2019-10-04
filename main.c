#include <stdio.h>
#include <stdlib.h> 

#include "core/inout/parse_in.h"


int main(int argc, char **argv)
{
    float *data = malloc(sizeof(float)*100);

    read_float_input(data);

    return 0;
}