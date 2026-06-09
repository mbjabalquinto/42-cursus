#include "codexion.h"

void    *coder_routine(void *arg)
{
    t_coder *coder;

    coder = (t_coder *)arg;
    coder->last_compile_time = get_current_time(); // A valid 'last compile time' for the first cycle.
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

void    bubble_up(t_priority_queue *queue, int i)
{
    int father_pos;
    t_heap_node temp;

    while (i > 0)
    {
        father_pos = (i - 1) / 2;
        if (queue->array[i].priority < queue->array[father_pos].priority)
        {
            temp = queue->array[i];
            queue->array[i] = queue->array[father_pos];
            queue->array[father_pos] = temp;
        }
        else
            break;
        i = father_pos;
    }
}

void    queue_routine(t_coder *coder)
{
    t_priority_queue *queue;
    int insert_index;

    queue = coder->data->queue;
    insert_index = queue->size;
    pthread_mutex_lock(&coder->data->queue_mutex);
    queue->array[insert_index].coder = coder;
    if (coder->data->is_edf)
        queue->array[insert_index].priority = coder->last_compile_time + coder->data->time_to_burnout;
    else
        queue->array[insert_index].priority = get_current_time();
    queue->size++;
    bubble_up(queue, insert_index);
    pthread_mutex_unlock(&coder->data->queue_mutex);
}

void pop_queue(t_coder *coder)
{
    int left_son;
    int right_son;
    int i;

    i = 0;
    while ()
    {
        left_son = 2 * i + 1;
        right_son = 2 * i + 2;
        
    }
}

void    coder_cycle(t_coder *coder)
{
    queue_routine(coder); // Me llega un coder y lo paso por la rutina para insertarlo en el array y ordenarlo.
    pthread_mutex_lock(&coder->data->queue_mutex);
    while (coder != coder->data->queue->array[0].coder
        || get_current_time() - coder->left_dongle->last_use_time < coder->data->dongle_cooldown
        || get_current_time() - coder->right_dongle->last_use_time < coder->data->dongle_cooldown)
        pthread_cond_wait(&coder->data->cond_var, &coder->data->queue_mutex);
    pthread_mutex_unlock(&coder->data->queue_mutex);
    pthread_mutex_lock(coder->left_dongle);
    print_status(coder, "has taken a dongle");
    pthread_mutex_lock(coder->right_dongle);
    print_status(coder, "has taken a dongle");
    print_status(coder, "is compiling");
    coder->last_compile_time = get_current_time();
    ft_usleep(coder->data->time_to_compile, coder->data);
    coder->left_dongle->last_use_time = get_current_time();
    pthread_mutex_unlock(coder->right_dongle);
    coder->right_dongle->last_use_time = get_current_time();
    phtread_mutex_unlock(coder->left_dongle);
    pthread_cond_broadcast(&coder->data->cond_var); // aviso a los demás hilos de que he terminado.
    pop_queue(coder);
    print_status(coder, "is debugging");
    ft_usleep(coder->data->time_to_debug, coder->data);
    print_status(coder, "is refactoring");
    ft_usleep(coder->data->time_to_refactor, coder->data);
}
