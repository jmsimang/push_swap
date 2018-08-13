/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:19:44 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:46 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Determines the stack size, divides and conquers, and prints the stack
** operations on STDOUT.
*/

void		push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_move		move;

	while ((move = operation(length(stack_a), stack_a, stack_b)) != ok)
	{
		if (move == sa && write(1, "sa\n", 3))
			swap(stack_a);
		else if (move == pa && write(1, "pa\n", 3))
			push(stack_a, stack_b);
		else if (move == pb && write(1, "pb\n", 3))
			push(stack_b, stack_a);
		else if (move == ra && write(1, "ra\n", 3))
			rotate(stack_a);
		else if (move == rra && write(1, "rra\n", 4))
			reverse_rotate(stack_a);
		else if (move == rb && write(1, "rb\n", 3))
			rotate(stack_b);
		else if (move == rrb && write(1, "rrb\n", 4))
			reverse_rotate(stack_b);
		else if (move == rr && write(1, "rr\n", 3))
			rotate_stacks(stack_a, stack_b);
		else if (write(1, "rrr\n", 4))
			reverse_rotate_stacks(stack_a, stack_b);
	}
}

/*
** Checks arguments and runs the sorting algorithm.
*/

void		run_push_swap(t_stack **stack_a, t_stack **stack_b, char **argv)
{
	if (check_arguments(argv) == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	construct(stack_a, argv);
	push_swap(stack_a, stack_b);
}

/*
** Main method - PUSH_SWAP.
*/

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc != 2)
			++argv;
		else
		{
			if (ft_wdcount(argv[1], ' ') == 1)
			{
				if (check_arguments(&argv[1]) == 0)
					ft_putstr("Error\n");
				return (0);
			}
			argv = ft_strsplit(argv[1], ' ');
		}
		run_push_swap(&stack_a, &stack_b, argv);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
