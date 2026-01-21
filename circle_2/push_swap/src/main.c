/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:27:00 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/21 19:17:55 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node *temp;

	temp = *stack;
	while ((*stack) -> next)
	{
		free(*stack);
		temp = temp -> next;
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
			return (0);
		stack_a = stack_a -> next;
	}
	return (1);
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
		return (0);
	new = malloc(1 * (sizeof(t_stack_node)));
	last = find_last_node(*stack_a);
	if (!new)
	{
		free_stack(stack_a);
		return (0);
	}
	new -> nbr = nbr;
	new -> next = NULL;
	new -> prev = last;
	if (!*stack_a)
		*stack_a = new;
	else
		last -> next = new;
	return (1);
}

int	check_limits(char *num)
{
	long number;

	number = ft_atol(num);
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	check_errors(char *num)
{
	int	i;
	
	i = 0;
	while (num[i])
	{
		if (num[i] == '+' || num[i] == '-')
		{
			if (i != 0)
				return (0);
		}
		else if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	init_stack(t_stack_node **stack_a, char *arg)
{
	int		i;
	char	**num;
	int		nbr;

	i = 0;
	num = ft_split(arg, ' ');
	while (num[i])
	{
		if (!check_errors(num[i]))
			return (0);
		if (!check_limits(num[i]))
			return (0);
		nbr = ft_atoi(num[i]);
		if (!check_nbr(*stack_a, nbr)) // Le paso una copia.
			return (0);
		if (!add_node(stack_a, nbr))
			return (0);
		i++;
	}
	free_split(num);
	return (1);
}

int	main	(int argc, char **argv)
{
	int i;
	t_stack_node *stack_a;

	stack_a = NULL;
	i = 1;
	if (argc == 1)
		return (1);
	while (argc > 1)
	{
		if (!init_stack(&stack_a, argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
		argc--;
	}
	return (0);
}