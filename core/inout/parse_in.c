#include "parse_in.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define ARRAY_LEN_INCREMENTATION 3
void *data_in;
int currently_allocated;
int data_in_counter;

/*
Private functions
*/
int allocate_space(void *value);
int append_data(void *value);


int read_args(int argc, char **argv, void *__data)
{   
    PARSE_IN_DEBUG("You've insert %d arguments\n", argc);

    for (int i = 0; i < argc; ++i) 
        PARSE_IN_DEBUG("%s\n", argv[i]); 

    return 0;
}

int read_float_input(float *data)
{
    char *input_line = NULL;      /* buffer to hold input on stdin    */
    char *nptr = NULL;
    char *endptr = NULL; 

    printf ("\nInput: ");
    scanf ("%m[^\n]%*c", &input_line); 
    
    nptr = input_line;
    float current_value = strtof (nptr, &endptr);
    allocate_space(&current_value);
    
    while (*nptr)
    {
        /* 
        test if there is a conversion
        set the nptr with the endptr for read the next value
        save the double value
        */
        if (nptr != endptr) {                            
            nptr = endptr;
            PARSE_IN_DEBUG ("float %f\n", current_value); 
            append_data(&current_value);
        }
        /* 
        skip everything is not convertible (spaces and comma separators)
        */
        nptr++;

        /*
        Convert the value to double
        */
        current_value = strtof (nptr, &endptr);
    }

    /* 
    free the memory allocated by scanf   
    */
    if (input_line) free (input_line);

    double *d = (float*)data_in;
    for(int i = 0; i<data_in_counter; i++){
        PARSE_IN_DEBUG ("double[i] %lf\n", d[i]);
    }
}

int allocate_space(void *data)
{
    PARSE_IN_DEBUG ("Init the memory to store the data\n");
    data_in = malloc(sizeof(data) * ARRAY_LEN_INCREMENTATION);
    
    if(data_in == NULL) {
        PARSE_IN_DEBUG ("No enough mem to do alloc\n");
        return -1;
    }
    currently_allocated = ARRAY_LEN_INCREMENTATION;
    data_in_counter = 0;
}

int append_data(void *value)
{   
    int value_dim = sizeof(value);
    memcpy(data_in+data_in_counter*value_dim, value, value_dim);
    data_in_counter++;

    if(data_in_counter >= currently_allocated - 1){
        PARSE_IN_DEBUG ("Time to realloc\n");
        currently_allocated += ARRAY_LEN_INCREMENTATION;
        void * temp = realloc(data_in, value_dim * currently_allocated);
        if (temp == NULL){
            PARSE_IN_DEBUG ("No enough mem to do realloc\n");
            return -1;
        }
        data_in = temp;
    }
}
