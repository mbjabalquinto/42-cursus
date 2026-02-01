/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:37 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/01 15:19:31 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	prep_for_push(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node -> above_median)
				ra(stack, TRUE);
			else
				rra(stack, TRUE);
		}
		if (stack_name == 'b')
		{
			if (node -> above_median)
				rb(stack, TRUE);
			else
				rrb(stack, TRUE);
		}
	}
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (!stack -> cheapest)
		stack = stack -> next;
	return (stack);
}

void	move_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*target_node;

	target_node = NULL;
	cheapest_node = return_cheapest(*stack_a);
	if (!cheapest_node)
		return ;
	target_node = cheapest_node -> target_node;
	if (cheapest_node -> above_median && target_node -> above_median)
	{
		while (cheapest_node != *stack_a && target_node != *stack_b)
			rr(stack_a, stack_b, TRUE);
	}
	else if (!cheapest_node -> above_median && !target_node -> above_median)
	{
		while (cheapest_node != *stack_a && target_node != *stack_b)
			rrr(stack_a, stack_b, TRUE);
	}
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, target_node, 'b');
	pb(stack_b, stack_a, TRUE);
}

int	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!sort_stacks(stack_a, stack_b))
		return (FALSE);
	return (TRUE);
}
