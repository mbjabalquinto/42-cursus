/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:47 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/11 16:01:47 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	get_start_time(t_data *args)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == 0)
	{
		args->global_start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		return (1);
	}
	return (0);
}

size_t	get_current_time(void)
{
	struct	timeval tv;

	if (gettimeofday(&tv, NULL) == 0)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (0);
}

int	simulation_should_stop(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->flag_end);
	stop = data->simulation_end;
	pthread_mutex_unlock(&data->flag_end);
	return (stop);
}

void	print_status(t_coder *coder, char *status)
{
	size_t time;

	pthread_mutex_lock(&coder->data->log_mutex);
	time = get_current_time();
	if(time != 0 && !simulation_should_stop(coder->data))
		printf("%zu %d %s\n", time - coder->data->global_start_time, coder->id, status);
	pthread_mutex_unlock(&coder->data->log_mutex);
}

void	ft_usleep(size_t time_to_check, t_data *data)
{
	size_t goal_time;
	size_t current_time;

	current_time = get_current_time();
	goal_time = current_time + time_to_check;
	while (current_time < goal_time)
	{
	if (simulation_should_stop(data))
			break;
		usleep(500);
		current_time = get_current_time();
	}
}