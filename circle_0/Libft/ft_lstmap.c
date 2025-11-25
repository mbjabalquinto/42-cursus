/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:09:31 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/25 16:27:56 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*create_node()
{
	t_list	*node;

	
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*lst2;
	void	*new_content;

	if (lst == NULL)
		return (NULL);
	new_content = f(lst -> content);
	lst2 = ft_lstnew(new_content);
	if (!lst2)
	{
		del(new_content);
		ft_lstclear(&lst2, del);
		return (NULL);
	}
	if (lst -> next == NULL)
	{
		lst2 -> next = NULL;
		return (lst2);
	}
	lst = lst -> next;
	while (lst != NULL)
	{
		new_content = f(lst -> content);
		node = ft_lstnew(new_content);
		if (!node)
		{
			del(new_content);
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, node);
		lst = lst -> next;
	}
	node -> next = NULL;
	return (lst2);
}
