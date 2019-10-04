#include "parse_in.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define ARRAY_LEN_INCREMENTATION 3
double *data_in;
int currently_allocated;
int data_in_counter;

/*
Private functions
*/
int allocate_space();
int append_data(double *value);


int read_args(int argc, char **argv, double *__data)
{   
    PARSE_IN_DEBUG("You've insert %d arguments\n", argc);

    for (int i = 0; i < argc; ++i) 
        PARSE_IN_DEBUG("%s\n", argv[i]); 

    return 0;
}

int read_input(double *data)
{
    char *input_line = NULL;      /* buffer to hold input on stdin    */
    char *nptr = NULL;
    char *endptr = NULL; 
    double current_value;

    printf ("\nInput: ");
    scanf ("%m[^\n]%*c", &input_line); 
    
    nptr = input_line;
    allocate_space(&current_value);
    
    while (*nptr)
    {
        /*
        Convert the value to double
        */
        current_value = strtof (nptr, &endptr);
        /* 
        test if there is a conversion
        set the nptr with the endptr for read the next value
        save the double value
        */
        if (nptr != endptr) {                            
            nptr = endptr;
            PARSE_IN_DEBUG ("double %f\n", current_value); 
            append_data(&current_value);
        }
        /* 
        skip everything is not convertible (spaces and comma separators)
        */
        nptr++;
    }

    /* 
    free the memory allocated by scanf   
    */
    if (input_line) free (input_line);

    for(int i = 0; i<data_in_counter; i++){
        PARSE_IN_DEBUG ("double[i] %lf\n", data_in[i]);
    }
}

int allocate_space()
{
    PARSE_IN_DEBUG ("Init the memory to store the data\n");
    data_in = malloc(sizeof(double) * ARRAY_LEN_INCREMENTATION);
    
    if(data_in == NULL) {
        PARSE_IN_DEBUG ("No enough mem to do alloc\n");
        return -1;
    }
    currently_allocated = ARRAY_LEN_INCREMENTATION;
    data_in_counter = 0;
}

int append_data(double *value)
{   
    data_in[data_in_counter] = *value;
    data_in_counter++;

    if(data_in_counter >= currently_allocated - 1){
        PARSE_IN_DEBUG ("Time to realloc\n");
        currently_allocated += ARRAY_LEN_INCREMENTATION;
        double * temp = realloc(data_in, sizeof(double) * currently_allocated);
        if (temp == NULL){
            PARSE_IN_DEBUG ("No enough mem to do realloc\n");
            return -1;
        }
        data_in = temp;
    }
}
