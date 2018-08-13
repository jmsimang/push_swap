/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:19:11 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:13 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Checks arguments and reads the instructions from STDIN in order to
** run the sorting algorithm.
*/

void		run_checker(t_stack **stack, char **argv)
{
	t_stack		*stack_b;
	char		*args;

	stack_b = NULL;
	if (check_arguments(argv) == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	construct(stack, argv);
	while (get_next_line(0, &args) > 0)
		instructions(stack, &stack_b, args);
	check_sorting(*stack) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	free(stack_b);
}

/*
** Main method - CHECKER.
*/

int			main(int argc, char **argv)
{
	t_stack		*stack;

	stack = NULL;
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
		run_checker(&stack, argv);
	}
	free(stack);
	return (0);
}
