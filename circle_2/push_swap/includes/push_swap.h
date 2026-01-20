/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:53 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/19 11:55:07 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdbool.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr; // the number to sort.
	int					index; // the position of the number in the stack.
	int					push_cost; // the cost to move the number.
	bool				above_median; // the number is in the upper median or in the lower median.
	bool				cheapest; // the number is the cheapest to move.
	struct s_stack_node	*target_node; // pointer to target node in the other stack.
	struct s_stack_node	*next; // pointer to the next node.
	struct s_stack_node	*prev; // pointer to the prev node.
}	t_stack_node;

#endif