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

int create_coders(t_data *args)
{
    int i;

    i = 0;
    args->coders = malloc(args->number_of_coders * sizeof(t_coder));
    args->mutexes = malloc(args->number_of_coders * sizeof(pthread_mutex_t));
    if (!args->coders || !args->mutexes)
        return (free_mem(0, args->mutexes, args->coders));
    while (i < args->number_of_coders)
    {
        if (pthread_mutex_init(&args->mutexes[i], NULL) != 0)
        {
            free_mem(i, args->mutexes, args->coders);
            return (1);
        }
        args->coders[i].id = i + 1;
        args->coders[i].compile_count = 0;
        args->coders[i].data = args;
        args->coders[i].left_dongle = &args->mutexes[i];
        args->coders[i].right_dongle = &args->mutexes[(i + 1) % args->number_of_coders];
        i++;
    }
    return (0);
}
int launch_threads()
{

}