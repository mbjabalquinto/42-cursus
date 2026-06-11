/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:26:36 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/11 15:23:48 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	clean_teardown(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->flag_end);
	pthread_mutex_destroy(&data->queue_mutex);
	while (i < data->number_of_coders)
	{
		pthread_mutex_destroy(&data->dongles[i].mutex);
		pthread_mutex_destroy(&data->coders[i].mon_mutex);
		i++;
	}
	free(data->queue->array);
	free(data->queue);
	free(data->coders);
	free(data->dongles);
}
