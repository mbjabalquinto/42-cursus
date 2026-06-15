/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:27 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/13 10:21:27 by mjabalqu         ###   ########.fr       */
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
		if (argv[i][0] == '\0')
			return (0);
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

static int	asig_data(t_data *args, char **argv)
{
	args->number_of_coders = ft_atol(argv[1]);
	if (args->number_of_coders <= 0)
		return (1);
	args->time_to_burnout = ft_atol(argv[2]);
	if (args->time_to_burnout <= 0)
		return (1);
	args->time_to_compile = ft_atol(argv[3]);
	if (args->time_to_compile <= 0)
		return (1);
	args->time_to_debug = ft_atol(argv[4]);
	if (args->time_to_debug <= 0)
		return (1);
	args->time_to_refactor = ft_atol(argv[5]);
	if (args->time_to_refactor <= 0)
		return (1);
	args->number_of_compiles_required = ft_atol(argv[6]);
	args->dongle_cooldown = ft_atol(argv[7]);
	if (strcmp(argv[8], "fifo") == 0)
		args->is_edf = 0;
	else
		args->is_edf = 1;
	return (0);
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
	if (pthread_cond_init(&args->cond_var, NULL) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		pthread_mutex_destroy(&args->queue_mutex);
		return (1);
	}
	return (0);
}

int	codexion(t_data *args, char **argv)
{
	if (asig_data(args, argv) != 0)
		return (0);
	if (init_global_mutexes(args) != 0)
		return (0);
	if (create_coders(args) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		pthread_mutex_destroy(&args->queue_mutex);
		return (0);
	}
	if (init_queue(args) != 0)
	{
		pthread_mutex_destroy(&args->log_mutex);
		pthread_mutex_destroy(&args->flag_end);
		pthread_mutex_destroy(&args->queue_mutex);
		free_mem(args->number_of_coders, args->dongles, args->coders);
		return (0);
	}
	if (get_start_time(args))
		return (args->number_of_compiles_required == 0
			||start_simulation(args));
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	args;

	if (argc != 9)
	{
		printf("Incorrect amount of parameters..");
		return (1);
	}
	else if (parse_errors(argv) && codexion(&args, argv))
	{
		clean_teardown(&args);
		return (0);
	}
	else
	{
		printf("Argument error: one or more arguments are invalid..\n");
		printf("Usage:\n");
		printf("./codexion <number_of_coders> <time_to_burnout> ");
		printf("<time_to_compile> <time_to_debug> <time_to_refactor> ");
		printf("<number_of_compiles_required> <dongle_cooldown> <scheduler>\n");
		return (1);
	}
	return (0);
}
