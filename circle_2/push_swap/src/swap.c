/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:42:53 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/22 11:55:07 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack_node **stack)
{
    t_stack_node    *temp;

    temp = *stack;
    *stack = (*stack) -> next;
    (*stack) -> next = temp;
}

void    push(t_stack_node **target, t_stack_node **source)
{

}
// first node become the last one.
void    rotate(t_stack_node **stack)
{
    t_stack_node    *head;
    t_stack_node    *temp;
    t_stack_node    *tale;

    head = *stack;
    tale = find_last_node(*stack);
    while (*stack)
    {

    }
}

void    rrotate(t_stack_node **stack)
{

}