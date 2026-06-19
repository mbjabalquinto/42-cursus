/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:21:02 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/19 17:29:35 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	can_take_dongles(t_coder *coder)
{
	int			left_pos;
	int			right_pos;
	int			total_coders;
	t_coder		*left_c;
	t_coder 	*right_c;
	size_t		coder_p;
	t_heap_node	*array;
	int			my_pos;

	if (coder->left_d->in_use || coder->right_d->in_use)
		return (0);
	my_pos = coder->id - 1;
	array = coder->data->queue->array;
	coder_p = array[coder->index].priority;
	total_coders = coder->data->number_of_coders;
	left_pos = (my_pos - 1 + total_coders) % total_coders;
	right_pos = (my_pos + 1) % total_coders;
	left_c = &coder->data->coders[left_pos];
	right_c = &coder->data->coders[right_pos];
	if (left_c->index != - 1 && array[left_c->index].priority < coder_p)
		if (left_c->left_d->in_use == 0 && left_c->right_d->in_use == 0)
			return (0);
	if (right_c->index != - 1 && array[right_c->index].priority < coder_p)
		if (right_c->left_d->in_use == 0 && right_c->right_d->in_use == 0)
			return (0);
	return (1);
}

int	get_dongles(t_coder *coder)
{
	while (1)
	{
		if (simulation_should_stop(coder->data))
			return (1);
		if (can_take_dongles(coder))
		{
			coder->left_d->in_use = 1;
			coder->right_d->in_use = 1;
			break ;
		}
		pthread_cond_wait(&coder->data->cond_var, &coder->data->queue_mutex);
	}
	return (0);
}

void	take_dongles(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;

	if (coder->left_d < coder->right_d)
	{
		first = coder->left_d;
		second = coder->right_d;
	}
	else
	{
		first = coder->right_d;
		second = coder->left_d;
	}
	pthread_mutex_lock(&first->mutex);
	print_status(coder, "has taken a dongle");
	pthread_mutex_lock(&second->mutex);
	print_status(coder, "has taken a dongle");
}

int	check_cooldown(t_coder *coder)
{
	return (get_current_time() - coder->left_d->last_use_time
		>= coder->data->dongle_cooldown
		&& get_current_time() - coder->right_d->last_use_time
		>= coder->data->dongle_cooldown);
}
