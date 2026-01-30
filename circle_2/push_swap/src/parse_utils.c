/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:58:15 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/30 17:07:45 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
