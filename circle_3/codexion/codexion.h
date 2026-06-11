/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:13 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/11 15:27:41 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_coder	t_coder;
typedef struct s_dongle	t_dongle;
typedef struct s_priority_queue	t_priority_queue;

typedef struct s_data
{
	int					number_of_coders;
	size_t				time_to_burnout;
	size_t				time_to_compile;
	size_t				time_to_debug;
	size_t				time_to_refactor;
	int					number_of_compiles_required;
	size_t				dongle_cooldown;
	int					is_edf;// fifo = 0 | edf = 1
	size_t				global_start_time;
	t_coder				*coders;
	t_dongle			*dongles;
	pthread_mutex_t		log_mutex;
	pthread_mutex_t		flag_end;
	pthread_mutex_t		queue_mutex;
	int					simulation_end;
	t_priority_queue	*queue;
	pthread_cond_t		cond_var;
	pthread_t			monitor_thread;
}	t_data;

// Programmer structure
typedef struct s_coder
{
	int				id;
	pthread_t		thread_id;
	int				burnout;
	int				compile_count;
	t_dongle		*left_dongle;
	t_dongle		*right_dongle;
	struct s_data	*data;
	size_t			last_compile_time;
	pthread_mutex_t	mon_mutex;
}	t_coder;

// Node to insert into the queue
typedef struct s_heap_node
{
	t_coder	*coder;
	size_t	priority;// Timestamp in FIFO, deadline in EDF.
}	t_heap_node;

// The queue's structure
typedef struct s_priority_queue
{
	t_heap_node	*array;
	int			size;// How much coders are there on the queue right now.
}	t_priority_queue;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	size_t			last_use_time;
}	t_dongle;

int		create_coders(t_data *args);
int		free_mem(int i, t_dongle *dongles, t_coder *coders);
int		start_simulation(t_data *args);
size_t	get_current_time(void);
void	*coder_routine(void *arg);
void	ft_usleep(size_t time_to_check, t_data *data);
int		get_start_time(t_data *args);
int		init_queue(t_data *args);
void	bubble_up(t_priority_queue *queue, int i);
void	pop_queue(t_priority_queue *queue);
void	ft_swap(t_priority_queue *queue, int i, int smallest);
void	clean_teardown(t_data *data);
int		simulation_should_stop(t_data *data);
void	print_status(t_coder *coder, char *status);

