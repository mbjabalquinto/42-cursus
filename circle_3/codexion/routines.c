#include "codexion.h"

void *coder_routine(void *arg)
{
    t_coder *coder;

    coder = (t_coder *)arg;
    coder->last_compile_time = get_current_time(coder->data);
    if (coder->id % 2 == 0)
            ft_usleep(10, coder->data);
    while (1)
    {
        if (simulation_should_stop(coder->data))
            break;
        coder_cycle(coder);
    }
    return (NULL);
}

void coder_cycle(t_coder *coder)
{
    pthread_mutex_lock(coder->left_dongle);
    print_status(coder, "has taken a dongle");
    pthread_mutex_lock(coder->right_dongle);
    print_status(coder, "has taken a dongle");
    print_status(coder, "is compiling");
    coder->last_compile_time = get_current_time(coder->data);
    ft_usleep(coder->data->time_to_compile, coder->data);
    pthread_mutex_unlock(coder->right_dongle);
    phtread_mutex_unlock(coder->left_dongle);
    print_status(coder, "is debugging");
    ft_usleep(coder->data->time_to_debug, coder->data);
    print_status(coder, "is refactoring");
    ft_usleep(coder->data->time_to_refactor, coder->data);
}
