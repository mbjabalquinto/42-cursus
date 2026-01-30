/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:24:49 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/30 14:00:42 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}
