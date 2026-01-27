/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:37 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/27 14:19:28 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



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
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	return (true);
}

int	set_current_position(t_stack_node *stack_a)
{
	int	i;
	int	center;

	i = 0;
	if (!stack_a)
		return (false);
	center = stack_len(stack_a) / 2;
	while (stack_a)
	{
		stack_a -> index = i;
		if (i > center)
			stack_a -> above_median = false;
		else
			stack_a -> above_median = true;
		i++;
		stack_a = stack_a -> next;
	}
	return (true);
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
			return (false);
		stack_a = stack_a -> next;
	}
	return (true);
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
	t_stack_node *new;
	t_stack_node *last;

	if (!stack_a)
		return (false);
	new = malloc(1 * (sizeof(t_stack_node)));
	if (!new)
		return (false);
	last = find_last_node(*stack_a);
	new -> nbr = nbr;
	new -> next = NULL;
	new -> prev = last;
	new -> index = stack_len(*stack_a);
	if (!*stack_a)
		*stack_a = new;
	else
		last -> next = new;
	return (true);
}

int	check_errors(char *num)
{
	int	i;
	
	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (!num[i])
		return (false);
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
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
	if (!set_current_position(*stack_a))
		return (false);
	if (!sort_stacks(stack_a, stack_b))
		return (false);
}
