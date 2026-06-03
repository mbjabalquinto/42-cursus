#include "codexion.h"
#include <stdio.h>
#include <string.h>

int parse_errors(char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < 8)
    {
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return(0);
            j++;
        }
        i++;
        j = 0;
    }
    if (strcmp(argv[i], "fifo") != 0 && strcmp(argv[i], "edf") != 0)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    arguments args;

    if (argc != 9)
    {
        printf("Incorrect amount of parameters..");
        return(1);
    }
    if (parse_errors(argv))
    {    
        args.number_of_coders = atoi(argv[1]);
        args.time_to_burnout = atoi(argv[2]);
        args.time_to_compile = atoi(argv[3]);
        args.time_to_debug = atoi(argv[4]);
        args.time_to_refactor = atoi(argv[5]);
        args.number_of_compiles_required = atoi(argv[6]);
        args.dongle_cooldown = atoi(argv[7]);
        args.scheduler = argv[8];
        codexion(&args);
    }
    else
    {
        printf("Argument error: one or more arguments are invalid..");
        return(1);
    }
    return (0);
}