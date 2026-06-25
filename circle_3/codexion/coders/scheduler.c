/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:57 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/19 14:22:18 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	insert_coder(t_coder *coder)
{
	t_priority_queue	*queue;
	int					insert_index;

	queue = coder->data->queue;
	insert_index = queue->size;
	queue->array[insert_index].coder = coder;
	coder->index = insert_index;
	if (coder->data->is_edf)
		queue->array[insert_index].priority
			= coder->last_compile_time + coder->data->time_to_burnout;
	else
		queue->array[insert_index].priority = get_current_time();
	queue->size++;
	bubble_up(queue, insert_index);
}

void	ft_swap(t_priority_queue *queue, int i, int smallest)
{
	t_heap_node	temp;

	temp = queue->array[i];
	queue->array[i] = queue->array[smallest];
	queue->array[smallest] = temp;
	queue->array[i].coder->index = i;
	queue->array[smallest].coder->index = smallest;
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

void	bubble_down(t_priority_queue *queue, int i)
{
	size_t		smallest;
	t_heap_node	*arr;

	arr = queue->array;
	while ((size_t)2 * i + 1 < queue->size)
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

void	remove_coder(t_priority_queue *queue, t_coder *coder)
{
	size_t	i;
	size_t	father;

	if (queue->size == 0)
		return ;
	queue->size--;
	i = coder->index;
	coder->index = -1;
	if (i == queue->size)
		return ;
	queue->array[i] = queue->array[queue->size];
	queue->array[i].coder->index = i;
	if (i > 0)
	{
		father = (i - 1) / 2;
		if (father >= 0
			&& queue->array[i].priority < queue->array[father].priority)
		{
			bubble_up(queue, i);
			return ;
		}
	}
	bubble_down(queue, i);
}
