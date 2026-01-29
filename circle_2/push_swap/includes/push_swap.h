/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:53 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 19:50:08 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef int bool;
# define true 1
# define false 0

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

long			ft_atol(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
t_stack_node	*find_last_node(t_stack_node *head);
int				check_nbr(t_stack_node *stack_a, int nbr);
void			free_split(char **num);
int				add_node(t_stack_node **stack_a, int nbr);
int				check_errors(char *num);
void			prep_for_push(t_stack_node **stack, t_stack_node *node, char stack_name);
t_stack_node	*return_cheapest(t_stack_node *stack);
void			move_cheapest(t_stack_node **stack_a, t_stack_node **stack_b);
int				init_stack(t_stack_node **stack_a, char *arg);
int				push_swap(t_stack_node **stack_a, t_stack_node **stack_b, char *arg);
void			min_on_top(t_stack_node **stack_a);
t_stack_node	*find_node_min(t_stack_node *stack_a);
void			set_target_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack_a);
void			set_cheapest(t_stack_node **stack_a);
void			cost_analysis(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*find_node_max(t_stack_node *stack_b);
void			set_target(t_stack_node **stack_a, t_stack_node **stack_b);
void			set_nodes(t_stack_node **stack_a, t_stack_node **stack_b);
int				stack_sorted(t_stack_node *stack_a);
int				sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b);
void			set_current_position(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_b, t_stack_node **stack_a);
void			sa(t_stack_node **stack_a);
void			sb(t_stack_node **stack_b);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void			swap(t_stack_node **stack);
void			push(t_stack_node **target, t_stack_node **source);
void			rotate(t_stack_node **stack);
void			rrotate(t_stack_node **stack);

#endif