/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:52 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/13 10:39:17 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	queue_routine(t_coder *coder)
{
	t_priority_queue	*queue;
	int					insert_index;

	queue = coder->data->queue;
	pthread_mutex_lock(&coder->data->queue_mutex);
	insert_index = queue->size;
	queue->array[insert_index].coder = coder;
	if (coder->data->is_edf)
		queue->array[insert_index].priority
			= coder->last_compile_time + coder->data->time_to_burnout;
	else
		queue->array[insert_index].priority = get_current_time();
	queue->size++;
	bubble_up(queue, insert_index);
	pthread_mutex_unlock(&coder->data->queue_mutex);
}

void	coder_compile(t_coder *coder)
{
	pthread_mutex_lock(&coder->left_d->mutex);
	print_status(coder, "has taken a dongle");
	pthread_mutex_lock(&coder->right_d->mutex);
	print_status(coder, "has taken a dongle");
	print_status(coder, "is compiling");
	pthread_mutex_lock(&coder->mon_mutex);
	coder->last_compile_time = get_current_time();
	pthread_mutex_unlock(&coder->mon_mutex);
	ft_usleep(coder->data->time_to_compile, coder->data);
	if (!simulation_should_stop(coder->data))
	{
		pthread_mutex_lock(&coder->mon_mutex);
		coder->compile_count++;
		pthread_mutex_unlock(&coder->mon_mutex);
	}
	pthread_mutex_lock(&coder->data->queue_mutex);
	coder->left_d->last_use_time = get_current_time();
	coder->right_d->last_use_time = get_current_time();
	coder->left_d->in_use = 0;
	coder->right_d->in_use = 0;
	pthread_mutex_unlock(&coder->data->queue_mutex);
	pthread_mutex_unlock(&coder->right_d->mutex);
	pthread_mutex_unlock(&coder->left_d->mutex);
}

static int	get_dongles(t_coder *coder)
{
	while (1)
	{
		if (simulation_should_stop(coder->data))
			return (1);
		if (coder == coder->data->queue->array[0].coder
			&& coder->left_d->in_use == 0 && coder->right_d->in_use == 0)
		{
			coder->left_d->in_use = 1;
			coder->right_d->in_use = 1;
			break ;
		}
		pthread_cond_wait(&coder->data->cond_var, &coder->data->queue_mutex);
	}
	return (0);
}

void	coder_cycle(t_coder *coder)
{
	queue_routine(coder);
	pthread_mutex_lock(&coder->data->queue_mutex);
	if (get_dongles(coder) != 0)
	{
		pthread_mutex_unlock(&coder->data->queue_mutex);
		return ;
	}
	pop_queue(coder->data->queue);
	pthread_cond_broadcast(&coder->data->cond_var);
	pthread_mutex_unlock(&coder->data->queue_mutex);
	while (!check_cooldown(coder))
	{
		if (simulation_should_stop(coder->data))
			return ;
		ft_usleep(1, coder->data);
	}
	coder_compile(coder);
	pthread_cond_broadcast(&coder->data->cond_var);
	print_status(coder, "is debugging");
	ft_usleep(coder->data->time_to_debug, coder->data);
	print_status(coder, "is refactoring");
	ft_usleep(coder->data->time_to_refactor, coder->data);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	if (coder->data->number_of_coders == 1)
	{
		pthread_mutex_lock(&coder->left_d->mutex);
		print_status(coder, "has taken a dongle");
		while (!simulation_should_stop(coder->data))
			ft_usleep(1, coder->data);
		pthread_mutex_unlock(&coder->left_d->mutex);
		return (NULL);
	}
	while (1)
	{
		if (simulation_should_stop(coder->data))
			break ;
		coder_cycle(coder);
	}
	return (NULL);
}
