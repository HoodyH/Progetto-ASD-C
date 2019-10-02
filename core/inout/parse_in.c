#include <stdio.h>
#include <stdlib.h> 

int read_args(int argc, char **argv)
{   
    printf("You've insert %d arguments\n", argc);

    for (int i = 0; i < argc; ++i) 
        printf("%s\n", argv[i]); 

    return 0;
}

int read_float_input(float *data){

    char *input_line = NULL;      /* buffer to hold input on stdin    */
    char *nptr = NULL;
    char *endptr = NULL; 
    float current_value = 0.0;

    printf ("\ninput: ");
    scanf ("%m[^\n]%*c", &input_line); 

    nptr = input_line;
    printf("%s\n", nptr);
    while (*nptr)
    {   
        /*
        Convert the value to float
        */
        current_value = strtof (nptr, &endptr);
        
        /* 
        test if there is a conversion
        set the nptr with the endptr for read the next value
        save the float value
        */
        if (nptr != endptr) {                                
            nptr = endptr;
            printf ("  float %f\n", current_value); 
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
}