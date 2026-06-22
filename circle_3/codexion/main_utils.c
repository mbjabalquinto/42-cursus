/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:26:36 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/19 12:12:23 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	clean_teardown(t_data *data)
{
	size_t	i;

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

long	ft_atol(const char *str)
{
	int		i;
	size_t	num;
	char	sign;

	sign = '+';
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = '-';
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (sign == '-')
		num = -num;
	return (num);
}
