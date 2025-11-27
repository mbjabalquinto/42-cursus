/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:12:42 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/19 18:47:11 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free_matrix(char ***matrix, int i)
{
	while (i >= 0)
	{
		free((*matrix)[i]);
		i--;
	}
	free(*matrix);
}
