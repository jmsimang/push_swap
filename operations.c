/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:19:35 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:38 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		add_to_stack(t_stack **stack, int digit)
{
	t_stack		*current;
	t_stack		*temp;

	current = *stack;
	if (current)
	{
		if (current->next != NULL)
			return (add_to_stack(&(current)->next, digit));
		else
		{
			temp = (t_stack *)malloc(sizeof(t_stack));
			temp->value = digit;
			temp->next = NULL;
			current->next = temp;
			return ;
		}
	}
	*stack = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->value = digit;
	(*stack)->next = NULL;
}

void		construct(t_stack **stack, char **argv)
{
	while (*argv != NULL)
	{
		add_to_stack(stack, ft_atoi(*argv));
		argv++;
	}
	check_duplicates(stack);
}

int			check_arguments(char **argv)
{
	int			i;
	int			j;

	i = -1;
	while (argv[++i] != NULL)
	{
		if (num_is_int(argv[i]) > MAX_INT || num_is_int(argv[i]) < MIN_INT)
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

void		free_stack(t_stack **stack)
{
	t_stack		*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		temp = NULL;
	}
}

/*
** Searches for the lowest number on the stack and returns it.
*/

int			min(t_stack **stack)
{
	int			num;
	t_stack		*temp;

	temp = *stack;
	num = temp->value;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->value < num)
			num = temp->value;
	}
	return (num);
}
