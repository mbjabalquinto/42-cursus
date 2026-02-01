/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:25:20 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/02/01 16:20:05 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	movements(char *movement, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_strcmp(movement, "sa\n") == 0)
		sa(stack_a, FALSE);
	else if (ft_strcmp(movement, "sb\n") == 0)
		sb(stack_b, FALSE);
	else if (ft_strcmp(movement, "ss\n") == 0)
		ss(stack_a, stack_b, FALSE);
	else if (ft_strcmp(movement, "pa\n") == 0)
		pa(stack_a, stack_b, FALSE);
	else if (ft_strcmp(movement, "pb\n") == 0)
		pb(stack_b, stack_a, FALSE);
	else if (ft_strcmp(movement, "ra\n") == 0)
		ra(stack_a, FALSE);
	else if (ft_strcmp(movement, "rb\n") == 0)
		rb(stack_b, FALSE);
	else if (ft_strcmp(movement, "rr\n") == 0)
		rr(stack_a, stack_b, FALSE);
	else if (ft_strncmp(movement, "rra\n", 4) == 0)
		rra(stack_a, FALSE);
	else if (ft_strncmp(movement, "rrb\n", 4) == 0)
		rrb(stack_b, FALSE);
	else if (ft_strncmp(movement, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, FALSE);
	else
		return (FALSE);
	return (TRUE);
}

void	checker(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*movement;

	movement = get_next_line(0);
	while (movement)
	{
		if (!movements(movement, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			free(movement);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		free (movement);
		movement = get_next_line(0);
	}
	if (stack_sorted(*stack_a) && stack_len(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int				i;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (1);
	while (argc > 1)
	{
		if (!init_stack(&stack_a, argv[i]))
		{
			write(2, "Error\n", 6);
			free_stack(&stack_a);
			return (1);
		}
		i++;
		argc--;
	}
	checker(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
