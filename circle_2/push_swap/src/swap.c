/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:42:53 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/30 14:13:36 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*node1;
	t_stack_node	*node2;
	t_stack_node	*node3;
	int				len;

	len = stack_len(*stack);
	if (len < 2)
		return ;
	node1 = *stack;
	*stack = (*stack)-> next;
	node2 = *stack;
	if (len > 2)
	{
		*stack = (*stack)-> next;
		node3 = *stack;
		node3 -> prev = node1;
		node1 -> next = node3;
	}
	else
		node1 -> next = NULL;
	node2 -> prev = NULL;
	node2 -> next = node1;
	node1 -> prev = node2;
	*stack = node2;
}

void	push(t_stack_node **target, t_stack_node **source)
{
	t_stack_node	*node_to_push;

	if (!*source)
		return ;
	node_to_push = *source;
	if ((*source)-> next)
	{
		*source = node_to_push -> next;
		(*source)-> prev = NULL;
	}
	else
		*source = NULL;
	if (*target)
	{
		(*target)-> prev = node_to_push;
		node_to_push -> next = *target;
	}
	else
	{
		node_to_push -> prev = NULL;
		node_to_push -> next = NULL;
	}
	*target = node_to_push;
}

//First node become the last one.
void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*temp;
	t_stack_node	*tale;

	if (!*stack || !(*stack)-> next)
		return ;
	temp = *stack;
	head = (*stack)-> next;
	head -> prev = NULL;
	tale = find_last_node(*stack);
	temp -> prev = tale;
	temp -> next = NULL;
	tale -> next = temp;
	*stack = head;
}

void	rrotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*temp;
	t_stack_node	*tale;

	if (!*stack || !(*stack)-> next)
		return ;
	temp = *stack;
	head = find_last_node(temp);
	tale = head -> prev;
	head -> prev = NULL;
	head -> next = temp;
	tale -> next = NULL;
	temp -> prev = head;
	*stack = head;
}
