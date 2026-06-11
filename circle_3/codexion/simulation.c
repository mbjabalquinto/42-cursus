/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:42 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/11 16:02:51 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->coders[i].mon_mutex);
	if (get_current_time() - data->coders[i].last_compile_time >= data->time_to_burnout)
	{
		pthread_mutex_lock(&data->flag_end);
		data->simulation_end = 1;
		pthread_mutex_unlock(&data->flag_end);
		pthread_mutex_lock(&data->log_mutex);
		printf("%zu %d burned out\n", get_current_time() - data->global_start_time, data->coders[i].id);
		pthread_mutex_unlock(&data->log_mutex);
		pthread_mutex_unlock(&data->coders[i].mon_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->coders[i].mon_mutex);
	return (0);
}

int check_all_compiled(t_data *data)
{
	int i;

	i = 0;
	if (data->number_of_compiles_required < 0)
		return (0);
	while (i < data->number_of_coders)
	{
		pthread_mutex_lock(&data->coders[i].mon_mutex);//si cualquiera está por debajo ya nos podemos salir.
		if (data->coders[i].compile_count < data->number_of_compiles_required)
		{
			pthread_mutex_unlock(&data->coders[i].mon_mutex);
			return (0);
		}
		i++;
		pthread_mutex_unlock(&data->coders[i].mon_mutex);
	}
	pthread_mutex_lock(&data->flag_end);
	data->simulation_end = 1;
	pthread_mutex_unlock(&data->flag_end);
	return (1);
}

void	*monitor_routine(void *args)
{
	int i;
	t_data *data;

	data = (t_data *)args;
	while (1)
	{
		i = 0;
		while (i < data->number_of_coders)
		{
			if (check_death(data, i))
				return (NULL);
			i++;
		}
		if (check_all_compiled(data))
			return (NULL);
		usleep(1000);
	}
}

int	start_simulation(t_data *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_coders)
	{
		if (pthread_create(&args->coders[i].thread_id, NULL, coder_routine, &args->coders[i]) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_cancel(args->coders[i].thread_id);
			}
			return (0);
		}
		i++;
	}
	while (i < args->number_of_coders)
	{
		pthread_join(args->coders[i].thread_id, NULL);
		i++;
	}
	pthread_create(&args->monitor_thread, NULL, monitor_routine, args);
	pthread_join(args->monitor_thread, NULL);
	i = 0;
	return (1);
}

