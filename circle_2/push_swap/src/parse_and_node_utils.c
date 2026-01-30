/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_node_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:19:25 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/30 14:05:53 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

int	check_nbr(t_stack_node *stack_a, int nbr)
{
	while (stack_a != NULL)
	{
		if (stack_a -> nbr == nbr)
			return (FALSE);
		stack_a = stack_a -> next;
	}
	return (TRUE);
}

void	free_split(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

int	add_node(t_stack_node **stack_a, int nbr)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack_a)
		return (FALSE);
	new = malloc(1 * (sizeof(t_stack_node)));
	if (!new)
		return (FALSE);
	last = find_last_node(*stack_a);
	new -> nbr = nbr;
	new -> next = NULL;
	new -> prev = last;
	new -> index = stack_len(*stack_a);
	if (!*stack_a)
		*stack_a = new;
	else
		last -> next = new;
	return (TRUE);
}

int	check_errors(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (!num[i])
		return (FALSE);
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
