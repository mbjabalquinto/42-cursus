/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:21:02 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/06/17 18:21:05 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	can_take_dongles(t_coder *coder)
{
	int		i;
	t_coder	*urg;

	if (coder->left_d->in_use || coder->right_d->in_use)
		return (0);
	i = 0;
	while (i < coder->data->queue->size)
	{
		urg = coder->data->queue->array[i].coder;
		if (urg == coder)
			break ;
		if (urg->left_d->in_use == 0 && urg->right_d->in_use == 0)
		{
			if (coder->left_d == urg->left_d
				|| coder->left_d == urg->right_d
				|| coder->right_d == urg->left_d
				|| coder->right_d == urg->right_d)
				return (0);
		}
		i++;
	}
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
