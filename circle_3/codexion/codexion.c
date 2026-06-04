#include "codexion.h"

void    codexion(t_data *args)
{
    t_coder *coders;
    int i;

    i = 0;
    coders = malloc(args->number_of_coders + 1 * sizeof(t_data));
    if (!coders)
        return (1);
    while (i < args->number_of_coders)
    {
        coders[i].id = i + 1;
        coders[i].
        i++;
    }
}
