/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:37:16 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/10 10:42:05 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    if (!begin_list)
        return ;
    while (begin_list)
    {
        f(begin_list -> data);
        begin_list = begin_list -> next;
    }
}
