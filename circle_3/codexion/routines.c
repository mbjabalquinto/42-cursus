/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:52 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/10 19:12:40 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
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

void	bubble_up(t_priority_queue *queue, int i)
{
	int			father_pos;
	t_heap_node	temp;

	while (i > 0)
	{
		father_pos = (i - 1) / 2;
		if (queue->array[i].priority < queue->array[father_pos].priority)
			ft_swap(queue, i, father_pos);
		else
			break;
		i = father_pos;
	}
}

void	queue_routine(t_coder *coder)
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

void pop_queue(t_priority_queue *queue)
{
	int			smallest;
	int			i;
	t_heap_node	*arr;

	i = 0;
	queue->size--;
	if (queue->size == 0)
		return;
	arr = queue->array;
	arr[0] = arr[queue->size];// quito al primero de la lista y relleno con el último.
	while (2 * i + 1 < queue->size)// mientras tenga al menos un hijo izquierdo.
	{
		smallest = 2 * i + 1;// asumo que el izquierdo es el mas pequeno hasta que se desmuestre lo contario.
		if (smallest + 1 < queue->size && \
			arr[smallest + 1].priority < arr[smallest].priority)
			smallest++;
		if (arr[i].priority <= arr[smallest].priority)
			break;
		ft_swap(queue, i, smallest);
		i = smallest;// cambio a la nueva posición para seguir bajando por el árbol.
	}
}

void	coder_cycle(t_coder *coder)
{
	queue_routine(coder); // Me llega un coder y lo paso por la rutina para insertarlo en el array y ordenarlo.
	pthread_mutex_lock(&coder->data->queue_mutex);
	while (coder != coder->data->queue->array[0].coder || \
		get_current_time() - coder->left_dongle->last_use_time < coder->data->dongle_cooldown || \
		get_current_time() - coder->right_dongle->last_use_time < coder->data->dongle_cooldown)
		pthread_cond_wait(&coder->data->cond_var, &coder->data->queue_mutex);
	pop_queue(coder->data->queue);
	pthread_mutex_unlock(&coder->data->queue_mutex);
	pthread_mutex_lock(coder->left_dongle);
	print_status(coder, "has taken a dongle");
	pthread_mutex_lock(coder->right_dongle);
	print_status(coder, "has taken a dongle");
	print_status(coder, "is compiling");
	coder->last_compile_time = get_current_time();
	coder->compile_count++;
	ft_usleep(coder->data->time_to_compile, coder->data);
	coder->left_dongle->last_use_time = get_current_time();
	pthread_mutex_unlock(coder->right_dongle);
	coder->right_dongle->last_use_time = get_current_time();
	phtread_mutex_unlock(coder->left_dongle);
	pthread_cond_broadcast(&coder->data->cond_var);// aviso a los demás hilos de que he terminado.
	print_status(coder, "is debugging");
	ft_usleep(coder->data->time_to_debug, coder->data);
	print_status(coder, "is refactoring");
	ft_usleep(coder->data->time_to_refactor, coder->data);
}
