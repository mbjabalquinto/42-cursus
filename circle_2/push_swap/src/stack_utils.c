/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:17:00 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/01 15:13:46 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// return TRUE if stack A is ordered.
int	stack_sorted(t_stack_node *stack_a)
{
	t_stack_node	*next;

	if (!stack_a)
		return (TRUE);
	while (stack_a -> next)
	{
		next = stack_a -> next;
		if (stack_a -> nbr > next -> nbr)
			return (FALSE);
		stack_a = stack_a -> next;
	}
	return (TRUE);
}

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
			stack -> above_median = FALSE;
		else
			stack -> above_median = TRUE;
		i++;
		stack = stack -> next;
	}
}

int	stack_len(t_stack_node	*stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = (*stack)-> next;
		free(*stack);
		*stack = temp;
	}
}
