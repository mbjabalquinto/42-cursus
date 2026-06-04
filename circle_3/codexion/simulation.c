#include "codexion.h"
#include <pthread.h>

int start_simulation(t_data *args)
{
    int i;

    i = 0;
    while (i < args->number_of_coders)
    {
        if (pthread_create(&args->coders[i].thread_id, NULL, coder_routine, &args->coders[i]) != 0)
        {
            while (i > 0)
            {
                i--;
                pthread_cancel(&args->coders[i].thread_id);
            }    
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < args->number_of_coders)
    {
        pthread_join(args->coders[i].thread_id, NULL);
        i++;
    }
    return (0);
}

void *coder_routine(void *arg)
{

}