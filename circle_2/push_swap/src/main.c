/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:27:00 by mjabalqu          #+#    #+#             */
/*   Updated: 2026/01/30 14:05:12 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (0);
		}
		i++;
		argc--;
	}
	if (!stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
