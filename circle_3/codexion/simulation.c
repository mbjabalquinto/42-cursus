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

int simulation_should_stop(t_data *data)
{
    int stop;

    pthread_mutex_lock(&data->flag_end);
    stop = data->simulation_end;
    pthread_mutex_unlock(&data->flag_end);
    return (stop);
}


void *coder_routine(void *arg)
{
    t_coder *coder;

    coder = (t_coder *)arg;
    while (1)
    {
    // comprobar si puede usar los dongles. Pueden estar bloqueados o enfriándose.
    // caso afirmativo los bloquea y también bloquea el printf
        pthread_mutex_lock(coder->left_dongle);
        pthread_mutex_lock(coder->right_dongle);
        pthread_mutex_lock(&coder->data->log_mutex);
        
    // una vez ha terminado de compilar libera los candados o los pone a enfriar.
    // Desconozco si tiene que avisar de que ha finalizado.
    // depura y refactoriza
    // comprueba si debe iniciar un nuevo ciclo con la flag. Si está bloqueada espera.
    if (simulation_should_stop(coder->data))
        break;
    }
    return (NULL);
}