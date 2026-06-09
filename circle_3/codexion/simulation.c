#include "codexion.h"

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
    monitor_routine(args);
    i = 0;
    while (i < args->number_of_coders)
    {
        pthread_join(args->coders[i].thread_id, NULL);
        i++;
    }
    return (0);
}

void monitor_routine(t_data *data)
{
    int i;

    while (1)
    {
        i = 0;
        while (i < data->number_of_coders)
        {
            if (get_current_time() - data->coders[i].last_compile_time >= data->time_to_burnout)
            {
                pthread_mutex_lock(&data->flag_end);
                data->simulation_end = 1;
                pthread_mutex_unlock(&data->flag_end);
                pthread_mutex_lock(&data->log_mutex);
                printf("%zu %d burned out", get_current_time() - data->global_start_time, data->coders[i].id);
                return ;
            }
            i++;
        }
        usleep(1000);
    }
}
