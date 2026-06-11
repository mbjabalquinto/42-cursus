/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:52 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/11 15:22:46 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	queue_routine(t_coder *coder)
{
	t_priority_queue *queue;
	int insert_index;

	queue = coder->data->queue;
	pthread_mutex_lock(&coder->data->queue_mutex);
	insert_index = queue->size;
	queue->array[insert_index].coder = coder;
	if (coder->data->is_edf)
		queue->array[insert_index].priority = coder->last_compile_time + coder->data->time_to_burnout;
	else
		queue->array[insert_index].priority = get_current_time();
	queue->size++;
	bubble_up(queue, insert_index);
	pthread_mutex_unlock(&coder->data->queue_mutex);
}

void	coder_compile(t_coder *coder)
{
	pthread_mutex_lock(&coder->left_dongle->mutex);
	print_status(coder, "has taken a dongle");
	pthread_mutex_lock(&coder->right_dongle->mutex);
	print_status(coder, "has taken a dongle");
	print_status(coder, "is compiling");
	pthread_mutex_lock(&coder->mon_mutex);
	coder->last_compile_time = get_current_time();
	coder->compile_count++;
	pthread_mutex_unlock(&coder->mon_mutex);
	ft_usleep(coder->data->time_to_compile, coder->data);
	coder->left_dongle->last_use_time = get_current_time();
	coder->right_dongle->last_use_time = get_current_time();
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
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
	coder_compile(coder);
	pthread_cond_broadcast(&coder->data->cond_var);// aviso a los demás hilos de que he terminado.
	print_status(coder, "is debugging");
	ft_usleep(coder->data->time_to_debug, coder->data);
	print_status(coder, "is refactoring");
	ft_usleep(coder->data->time_to_refactor, coder->data);
}

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
