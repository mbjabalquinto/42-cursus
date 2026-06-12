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
			break;
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
		return;
	arr = queue->array;
	arr[0] = arr[queue->size];// quito al primero de la lista y relleno con el último.
	while (2 * i + 1 < queue->size)// mientras tenga al menos un hijo izquierdo.
	{
		smallest = 2 * i + 1;// asumo que el izquierdo es el mas pequeno hasta que se desmuestre lo contario.
		if (smallest + 1 < queue->size && \
			arr[smallest + 1].priority < arr[smallest].priority)
			smallest++;
		if (arr[i].priority <= arr[smallest].priority)
			break;
		ft_swap(queue, i, smallest);
		i = smallest;// cambio a la nueva posición para seguir bajando por el árbol.
	}
}

int	check_cooldown(t_coder *coder)
{
	return (get_current_time() - coder->left_dongle->last_use_time >= coder->data->dongle_cooldown && \
	get_current_time() - coder->right_dongle->last_use_time >= coder->data->dongle_cooldown);
}
