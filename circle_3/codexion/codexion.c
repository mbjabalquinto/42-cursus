#include "codexion.h"

int free_mem(int i, pthread_mutex_t *mutexes, t_coder *coders)
{
    while (i > 0)
    {
        i--;
        pthread_mutex_destroy(&mutexes[i]);
    }
    free(mutexes);
    free(coders);
    return (1);
}

int    codexion(t_data *args)
{
    t_coder *coders;
    pthread_mutex_t *mutexes;
    int i;

    i = 0;
    coders = malloc(args->number_of_coders * sizeof(t_coder));
    mutexes = malloc(args->number_of_coders * sizeof(pthread_mutex_t));
    if (!coders || !mutexes)
        return (free_mem(0, mutexes, coders));
    while (i < args->number_of_coders)
    {
        if (pthread_mutex_init(&mutexes[i], NULL) != 0)
        {
            free_mem(i, mutexes, coders);
            return (1);
        }
        coders[i].id = i + 1;
        coders[i].compile_count = 0;
        coders[i].data = args;
        coders[i].left_dongle = &mutexes[i];
        coders[i].right_dongle = &mutexes[(i + 1) % args->number_of_coders];
        i++;
    }
    return (0);
}
