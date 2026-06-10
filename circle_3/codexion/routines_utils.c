#include "codexion.h"

void    ft_swap(t_priority_queue *queue, int i, int smallest)
{
    t_heap_node temp;

    temp = queue->array[i];
    queue->array[i] = queue->array[smallest];
    queue->array[smallest] = temp;
}