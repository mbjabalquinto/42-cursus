/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:52:57 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/10 19:13:01 by mjabalqu         ###   ########.fr       */
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