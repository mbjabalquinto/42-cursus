/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:57 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/12 13:09:29 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	ft_swap(t_priority_queue *queue, int i, int smallest)
{
	t_heap_node	temp;

	temp = queue->array[i];
	queue->array[i] = queue->array[smallest];
	queue->array[smallest] = temp;
}

void	bubble_up(t_priority_queue *queue, int i)
{
	int			father_pos;

	while (i > 0)
	{
		father_pos = (i - 1) / 2;
		if (queue->array[i].priority < queue->array[father_pos].priority)
			ft_swap(queue, i, father_pos);
		else
			break ;
		i = father_pos;
	}
}

void	pop_queue(t_priority_queue *queue)
{
	int			smallest;
	int			i;
	t_heap_node	*arr;

	i = 0;
	queue->size--;
	if (queue->size == 0)
		return ;
	arr = queue->array;
	arr[0] = arr[queue->size];
	while (2 * i + 1 < queue->size)
	{
		smallest = 2 * i + 1;
		if (smallest + 1 < queue->size
			&& arr[smallest + 1].priority < arr[smallest].priority)
			smallest++;
		if (arr[i].priority <= arr[smallest].priority)
			break ;
		ft_swap(queue, i, smallest);
		i = smallest;
	}
}

int	check_cooldown(t_coder *coder)
{
	return (get_current_time() - coder->left_d->last_use_time
		>= coder->data->dongle_cooldown
		&& get_current_time() - coder->right_d->last_use_time
		>= coder->data->dongle_cooldown);
}
