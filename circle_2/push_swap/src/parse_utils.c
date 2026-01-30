/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:58:15 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/30 17:17:18 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
