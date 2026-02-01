/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:24:49 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/01 15:12:21 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack_node **stack_a, int print)
{
	rrotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b, int print)
{
	rrotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	rrotate(stack_a);
	rrotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
