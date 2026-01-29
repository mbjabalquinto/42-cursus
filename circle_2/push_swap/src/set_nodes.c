/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:14:38 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 09:15:04 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack_node **stack_a)
{
	t_stack_node	*best_node;
	t_stack_node	*current_node;
	long			best_cost;

	if (!*stack_a)
		return ;
	best_node = NULL;
	best_cost = LONG_MAX;//to avoid problems with int limits. The value could be INT_MAX. In this case you shouldnt compare with >. LONG_MAX always will be > the first time.
	current_node = *stack_a;
	while (current_node)
	{
		current_node -> cheapest = false;
		if (best_cost > current_node -> push_cost)
		{
			best_cost = current_node -> push_cost;
			best_node = current_node;
		}
		current_node = current_node -> next;
	}
	best_node -> cheapest = true;
}

void	cost_analysis(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_node;
	int				len_a;
	int				len_b;
	int				cost;

	current_node = *stack_a;
	len_a = stack_len(*stack_a);
	len_b = stack_len(*stack_b);

	while (current_node)
	{
		cost = 0;
		target_node = current_node -> target_node;
		if (current_node -> above_median)
			cost += current_node -> index;
		else
			cost += len_a - current_node -> index;
		if (target_node -> above_median)
			cost += target_node -> index;
		else
			cost += len_b - target_node -> index;
		current_node -> push_cost = cost;
		current_node = current_node -> next;
	}
}

// To find the max value in stack B.
t_stack_node	*find_node_max(t_stack_node *stack_b)
{
	long	max;
	t_stack_node	*node_max;

	node_max = NULL;
	max = LONG_MIN;
	while (stack_b)
	{
		if (stack_b -> nbr > max)
		{	
			node_max = stack_b;
			max = stack_b -> nbr;
		}
		stack_b = stack_b -> next;
	}
	return (node_max);
}

// Looking for the next smaller number or the bigest.
// Its necessary to use LONG because we have to initialise the variable with a number smaller than INT_MIN. 
void	set_target(t_stack_node **stack_a, t_stack_node **stack_b)
{
	long			best_match_index;
	t_stack_node	*current_b;
	
	while (*stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = *stack_b;
		while (current_b)
		{
			if (current_b -> nbr > best_match_index && current_b -> nbr < (*stack_a) -> nbr)
			{	
				best_match_index = current_b -> nbr;
				(*stack_a) -> target_node = current_b;
			}
			current_b = current_b -> next;
		}
		if (best_match_index == LONG_MIN) // If they are the same its means that there isnt a smaller number. So we take the max.
			(*stack_a) -> target_node = find_node_max(stack_b);
		stack_a = (*stack_a) -> next;
	}
}

void	set_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_current_position(*stack_a);
	set_current_position(*stack_b);
	set_target(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}