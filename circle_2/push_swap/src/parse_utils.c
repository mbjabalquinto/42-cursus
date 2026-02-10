/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:58:15 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/01 14:04:55 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_empty_or_space(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '\0')
		return (TRUE);
	while (arg[i])
	{
		if (arg[i] != ' ' && arg[i] != '\t')
			return (FALSE);
		i++;
	}
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

int	init_stack(t_stack_node **stack_a, char *arg)
{
	int		i;
	char	**num;
	long	nbr;

	if (is_empty_or_space(arg))
		return (FALSE);
	i = 0;
	num = ft_split(arg, ' ');
	while (num[i])
	{
		if (!check_errors(num[i]))
			return (free_split(num), free_stack(stack_a), FALSE);
		nbr = ft_atol(num[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (free_split(num), free_stack(stack_a), FALSE);
		if (!check_nbr(*stack_a, nbr))
			return (free_split(num), free_stack(stack_a), FALSE);
		if (!add_node(stack_a, nbr))
			return (free_split(num), free_stack(stack_a), FALSE);
		i++;
	}
	free_split(num);
	return (TRUE);
}
