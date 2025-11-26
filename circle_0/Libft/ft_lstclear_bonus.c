/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:51:55 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/25 16:02:02 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == NULL)
		return ;
	temp = (*lst)-> next;
	while (*lst != NULL)
	{
		del((*lst)-> content);
		temp = (*lst)-> next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
