/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:53 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/26 16:02:25 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

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

int				init_stack(t_stack_node **stack_a, char *arg);
int				check_errors(char *num);
int				add_node(t_stack_node **stack_a, int nbr);
void			free_split(char **num);
int				check_nbr(t_stack_node *stack_a, int nbr);
t_stack_node	*find_last_node(t_stack_node *head);
void			free_stack(t_stack_node **stack);
int				stack_len(t_stack_node	*stack);
long			ft_atol(const char *str);
void			swap(t_stack_node **stack);
void			swap(t_stack_node **stack);
void			push(t_stack_node **target, t_stack_node **source);
void			rotate(t_stack_node **stack);
void			rrotate(t_stack_node **stack);

#endif