#include "codexion.h"
#include <pthread.h>
#include <unistd.h>

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

int simulation_should_stop(t_data *data)
{
    int stop;

    pthread_mutex_lock(&data->flag_end);
    stop = data->simulation_end;
    pthread_mutex_unlock(&data->flag_end);
    return (stop);
}

void print_status(t_coder *coder, char *status)
{
    size_t time;

    pthread_mutex_lock(&coder->data->log_mutex);
    if(!simulation_should_stop(coder->data) && get_current_time(coder->data))
    {
        time = coder->data->current_time - coder->data->global_start_time;
        printf("%zu %d %s\n", time, coder->id, status);
    }
    pthread_mutex_unlock(&coder->data->log_mutex);
}

void ft_usleep(size_t time_to_compile, t_data *data)
{
    size_t current_time;
    
    current_time = get_current_time(data);
    while (current_time < time_to_compile)
    {
        usleep(500);
    }
}

void *coder_routine(void *arg)
{
    t_coder *coder;

    coder = (t_coder *)arg;
    while (1)
    {
        if (simulation_should_stop(coder->data))
            break;
        pthread_mutex_lock(coder->left_dongle);
        print_status(coder, "has taken a dongle");
        pthread_mutex_lock(coder->right_dongle);
        print_status(coder, "has taken a dongle");
        print_status(coder, "is compiling");
        ft_usleep(coder->data->time_to_compile, coder->data);
        pthread_mutex_unlock(coder->right_dongle);
        phtread_mutex_unlock(coder->left_dongle);
        print_status(coder, "is debugging");
        ft_usleep(coder->data->time_to_debug, coder->data);
        print_status(coder, "is refactoring");
        ft_usleep(coder->data->time_to_refactor, coder->data);
    }
    return (NULL);
}
