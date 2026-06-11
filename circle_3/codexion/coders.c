/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:37 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/11 15:41:43 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	free_mem(int i, t_dongle *dongles, t_coder *coders)
{
	while (i > 0)
	{
		i--;
		pthread_mutex_destroy(&dongles[i].mutex);
		pthread_mutex_destroy(&coders[i].mon_mutex);
	}
	free(dongles);
	free(coders);
	return (0);
}

int	init_queue(t_data *args)
{
	args->queue = malloc(sizeof(t_priority_queue));
	if (!args->queue)
		return (1);
	args->queue->array = malloc(args->number_of_coders * sizeof(t_heap_node));
	if (!args->queue->array)
	{
		free(args->queue);
		return (1);
	}
	args->queue->size = 0;
	return (0);
}

static int	init_single_coder(t_data *args, int i)
{
	if (pthread_mutex_init(&args->dongles[i].mutex, NULL) != 0)
	{
		free_mem(i, args->dongles, args->coders);
		return (1);
	}
	if (pthread_mutex_init(&args->coders[i].mon_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&args->dongles[i].mutex);
		free_mem(i, args->dongles, args->coders);
		return (1);
	}
	args->coders[i].id = i + 1;
	args->coders[i].compile_count = 0;
	args->coders[i].data = args;
	args->coders[i].left_dongle = &args->dongles[i];
	args->coders[i].right_dongle = &args->dongles[(i + 1) % args->number_of_coders];
	args->coders[i].last_compile_time = get_current_time();
	args->dongles[i].last_use_time = 0;
	args->simulation_end = 0;
	return (0);
}

int	create_coders(t_data *args)
{
	int	i;

	i = 0;
	args->coders = malloc(args->number_of_coders * sizeof(t_coder));
	args->dongles = malloc(args->number_of_coders * sizeof(t_dongle));
	if (!args->coders || !args->dongles)
		return (free_mem(0, args->dongles, args->coders));
	while (i < args->number_of_coders)
	{
		if (init_single_coder(args, i) != 0)
			return (1);
		i++;
	}
	return (0);
}
