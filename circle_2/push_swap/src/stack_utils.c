/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:17:00 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 14:24:04 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return true if stack A is ordered.
int	stack_sorted(t_stack_node *stack_a)
{
	t_stack_node *next;
	
	if (!stack_a)
		return (true);
	while (stack_a -> next)
	{
		next = stack_a -> next;
		if (stack_a -> nbr > next -> nbr)
			return (false);
		stack_a = stack_a -> next;
	}
	return (true);
}

int	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (len_a > 3 && !stack_sorted(*stack_a))//Actions to take when there are more than 3 nodes and stack is not yet sorted.
	{
		set_nodes(stack_a, stack_b);
		move_cheapest(stack_a, stack_b);
		len_a--;
	}
	//TODO 
	set_nodes(stack_a, stack_b);//vuelvo a actualizar todo tras el ultimo movimiento del bucle.
	sort_three(stack_a);
	//moverlos de B a A
	return (true);
}
// set the current position of the node.
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack -> index = i;
		if (i > center)
			stack -> above_median = false;
		else
			stack -> above_median = true;
		i++;
		stack = stack -> next;
	}
}

int	stack_len(t_stack_node	*stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node *temp;

	while (*stack)
	{
		temp = (*stack) -> next;
		free(*stack);
		*stack = temp;
	}
}