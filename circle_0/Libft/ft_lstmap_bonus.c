/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:09:31 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/11/26 16:33:58 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	t_list	*create_node(t_list *lst,
		void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	void	*new_content;

	new_content = f(lst -> content);
	node = ft_lstnew(new_content);
	if (!node)
	{
		del(new_content);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		node = create_node(lst, f, del);
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (head == NULL)
			head = node;
		else
			ft_lstadd_back(&head, node);
		lst = lst -> next;
	}
	return (head);
}
