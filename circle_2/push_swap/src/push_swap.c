/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:37 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/29 09:11:03 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack_node **stack_a)
{
	t_stack_node	*best_node;
	t_stack_node	*current_node;
	long			best_cost;

	if (!*stack_a)
		return ;
	best_node = NULL;
	best_cost = LONG_MAX;//to avoid problems with int limits. The value could be INT_MAX. In this case you shouldnt compare with >. LONG_MAX always will be > the first time.
	current_node = *stack_a;
	while (current_node)
	{
		current_node -> cheapest = false;
		if (best_cost > current_node -> push_cost)
		{
			best_cost = current_node -> push_cost;
			best_node = current_node;
		}
		current_node = current_node -> next;
	}
	best_node -> cheapest = true;
}

void	cost_analysis(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_node;
	int				len_a;
	int				len_b;
	int				cost;

	current_node = *stack_a;
	len_a = stack_len(*stack_a);
	len_b = stack_len(*stack_b);

	while (current_node)
	{
		cost = 0;
		target_node = current_node -> target_node;
		if (current_node -> above_median)
			cost += current_node -> index;
		else
			cost += len_a - current_node -> index;
		if (target_node -> above_median)
			cost += target_node -> index;
		else
			cost += len_b - target_node -> index;
		current_node -> push_cost = cost;
		current_node = current_node -> next;
	}
}

// To find the max value in stack B.
t_stack_node	*find_node_max(t_stack_node *stack_b)
{
	long	max;
	t_stack_node	*node_max;

	node_max = NULL;
	max = LONG_MIN;
	while (stack_b)
	{
		if (stack_b -> nbr > max)
		{	
			node_max = stack_b;
			max = stack_b -> nbr;
		}
		stack_b = stack_b -> next;
	}
	return (node_max);
}

// Looking for the next smaller number or the bigest.
// Its necessary to use LONG because we have to initialise the variable with a number smaller than INT_MIN. 
void	set_target(t_stack_node **stack_a, t_stack_node **stack_b)
{
	long			best_match_index;
	t_stack_node	*current_b;
	
	while (*stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = *stack_b;
		while (current_b)
		{
			if (current_b -> nbr > best_match_index && current_b -> nbr < (*stack_a) -> nbr)
			{	
				best_match_index = current_b -> nbr;
				(*stack_a) -> target_node = current_b;
			}
			current_b = current_b -> next;
		}
		if (best_match_index == LONG_MIN) // If they are the same its means that there isnt a smaller number. So we take the max.
			(*stack_a) -> target_node = find_node_max(stack_b);
		stack_a = (*stack_a) -> next;
	}
}

void	set_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_current_position(*stack_a);
	set_current_position(*stack_b);
	set_target(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}

// return true if stack A is ordered.
int	stack_sorted(t_stack_node *stack_a)
{
	t_stack_node *next;
	
	if (!stack_a)
		return (true);
	while (stack_a -> next)
	{
		next = stack_a -> next;
		if (stack_a -> nbr > next -> nbr)
			return (false);
		stack_a = stack_a -> next;
	}
	return (true);
}

int	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	set_nodes(stack_a, stack_b);
	while (len_a > 3)//Actions to do when nodes are more than 3.
	{
		move_cheapest();
		len_a--;
		*stack_a = (*stack_a) -> next;
	}
	return (true);
}
// set the current position of the node.
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack -> index = i;
		if (i > center)
			stack -> above_median = false;
		else
			stack -> above_median = true;
		i++;
		stack = stack -> next;
	}
}

int	stack_len(t_stack_node	*stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node *temp;

	while (*stack)
	{
		temp = (*stack) -> next;
		free(*stack);
		*stack = temp;
	}
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

int	check_nbr(t_stack_node *stack_a, int nbr)
{
	while (stack_a != NULL)
	{
		if (stack_a -> nbr == nbr)
			return (false);
		stack_a = stack_a -> next;
	}
	return (true);
}

void	free_split(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

int	add_node(t_stack_node **stack_a, int nbr)
{
	t_stack_node *new;
	t_stack_node *last;

	if (!stack_a)
		return (false);
	new = malloc(1 * (sizeof(t_stack_node)));
	if (!new)
		return (false);
	last = find_last_node(*stack_a);
	new -> nbr = nbr;
	new -> next = NULL;
	new -> prev = last;
	new -> index = stack_len(*stack_a);
	if (!*stack_a)
		*stack_a = new;
	else
		last -> next = new;
	return (true);
}

int	check_errors(char *num)
{
	int	i;
	
	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (!num[i])
		return (false);
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

int	init_stack(t_stack_node **stack_a, char *arg)
{
	int		i;
	char	**num;
	long	nbr;

	i = 0;
	num = ft_split(arg, ' ');
	while (num[i])
	{
		if (!check_errors(num[i]))
			return (free_split(num), free_stack(stack_a), false); 
		nbr = ft_atol(num[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (free_split(num), free_stack(stack_a), false);
		if (!check_nbr(*stack_a, nbr))
			return (free_split(num), free_stack(stack_a), false);
		if (!add_node(stack_a, nbr))
			return (free_split(num), free_stack(stack_a), false);
		i++;
	}
	free_split(num);
	return (true);
}
int	push_swap(t_stack_node **stack_a, t_stack_node **stack_b, char *arg)
{
	if (!init_stack(stack_a, arg))
		return (false);
	if (!sort_stacks(stack_a, stack_b))
		return (false);
}
