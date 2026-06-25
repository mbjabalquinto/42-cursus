/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:52 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/19 13:13:36 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	coder_compile(t_coder *coder)
{
	take_dongles(coder);
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

void	coder_cycle(t_coder *coder)
{
	pthread_mutex_lock(&coder->data->queue_mutex);
	insert_coder(coder);
	if (get_dongles(coder) != 0)
	{
		pthread_mutex_unlock(&coder->data->queue_mutex);
		return ;
	}
	remove_coder(coder->data->queue, coder);
	pthread_cond_broadcast(&coder->data->cond_var);
	pthread_mutex_unlock(&coder->data->queue_mutex);
	while (!check_cooldown(coder))
	{
		if (simulation_should_stop(coder->data))
			return ;
		ft_usleep(1, coder->data);
	}
	coder_compile(coder);
	pthread_mutex_lock(&coder->data->queue_mutex);
	pthread_cond_broadcast(&coder->data->cond_var);
	pthread_mutex_unlock(&coder->data->queue_mutex);
	print_status(coder, "is debugging");
	ft_usleep(coder->data->time_to_debug, coder->data);
	print_status(coder, "is refactoring");
	ft_usleep(coder->data->time_to_refactor, coder->data);
}

int	coder_is_done(t_coder *coder)
{
	if (coder->compile_count >= coder->data->number_of_compiles_required)
	{
		pthread_mutex_lock(&coder->mon_mutex);
		coder->is_full = 1;
		pthread_mutex_unlock(&coder->mon_mutex);
		return (1);
	}
	return (0);
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
		if (coder_is_done(coder))
			break ;
		coder_cycle(coder);
	}
	return (NULL);
}
