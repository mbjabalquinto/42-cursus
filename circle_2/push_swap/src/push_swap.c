/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:37 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 14:12:36 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if(stack_len == 'a')
		{
			if (node -> above_median)
				ra(stack);
			else
				rra(stack);
		}
		if(stack_len == 'b')
		{
			if (node -> above_median)
				rb(stack);
			else
				rrb(stack);
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
	if (cheapest_node -> above_median && target_node -> above_median)//If both nodes are above median.
	{
		while (cheapest_node != *stack_a && target_node != *stack_b)//While none of them are at the top.
			rr(stack_a, stack_b);
	}
	else if (!cheapest_node -> above_median && !target_node -> above_median)//If both nodes are not above median.
	{		
		while (cheapest_node != *stack_a && target_node != *stack_b)//While none of them are at the top.
			rrr(stack_a, stack_b);
	}
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, target_node, 'b');
	pb(stack_b, stack_a);
}

int	init_stack(t_stack_node **stack_a, char *arg)
{
	int		i;
	char	**num;
	long	nbr;

	i = 0;
	num = ft_split(arg, ' ');
	while (num[i])
	{
		if (!check_errors(num[i]))
			return (free_split(num), free_stack(stack_a), false);
		nbr = ft_atol(num[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (free_split(num), free_stack(stack_a), false);
		if (!check_nbr(*stack_a, nbr))
			return (free_split(num), free_stack(stack_a), false);
		if (!add_node(stack_a, nbr))
			return (free_split(num), free_stack(stack_a), false);
		i++;
	}
	free_split(num);
	return (true);
}
int	push_swap(t_stack_node **stack_a, t_stack_node **stack_b, char *arg)
{
	if (!init_stack(stack_a, arg))
		return (false);
	if (!sort_stacks(stack_a, stack_b))
		return (false);
	return (true);
}
