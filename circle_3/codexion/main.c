/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:27 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/10 19:00:07 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	parse_errors(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 8)
	{
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	if (strcmp(argv[i], "fifo") != 0 && strcmp(argv[i], "edf") != 0)
		return (0);
	return (1);
}

static void	asig_data(t_data *args, char **argv)
{
	args->number_of_coders = atoi(argv[1]);
	args->time_to_burnout = atoi(argv[2]);
	args->time_to_compile = atoi(argv[3]);
	args->time_to_debug = atoi(argv[4]);
	args->time_to_refactor = atoi(argv[5]);
	args->number_of_compiles_required = atoi(argv[6]);
	args->dongle_cooldown = atoi(argv[7]);
	if (strcmp(argv[8], "fifo") == 0)
		args->is_edf = 0;
	else
		args->is_edf = 1;
}

static int	init_global_mutexes(t_data *args)
{
	if (pthread_mutex_init(&args->log_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&args->flag_end, NULL) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		return (1);
	}
	if (pthread_mutex_init(&args->queue_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		return (1);
	}
	if (pthread_mutex_init(&args->coders->mon_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&args->queue_mutex);
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		return (1);
	}
	return (0);
}

int	codexion(t_data *args, char **argv)
{
	asig_data(args, argv);
	if (init_global_mutexes(args) != 0)
		return (1);
	if (create_coders(args) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		pthread_mutex_destroy(&args->queue_mutex);
		return (1);
	}
	if (init_queue(args) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		pthread_mutex_destroy(&args->queue_mutex);
		return (1);
	}
	if (get_start_time(args))
		return (start_simulation(args));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	args;

	if (argc != 9)
	{
		printf("Incorrect amount of parameters..");
		return (1);
	}
	if (parse_errors(argv))
		return (codexion(&args, argv));
	else
	{
		printf("Argument error: one or more arguments are invalid..");
		return (1);
	}
	return (0);
}
