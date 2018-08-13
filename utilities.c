/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:19:52 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:53 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Checks if a stack is sorted in ASC order
*/

int			check_sorting(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	else if (!stack->next->next)
		return (stack->value < stack->next->value ? 1 : 0);
	else
	{
		while (stack && stack->next)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
}

/*
** Checks if a stack is sorted in DESC order
*/

int			check_reverse_sorting(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	else if (!stack->next->next)
		return (stack->value > stack->next->value ? 1 : 0);
	else
	{
		while (stack && stack->next)
		{
			if (stack->value < stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
}

/*
** Checks input for duplicates
*/

void		check_duplicates(t_stack **stack)
{
	t_stack		*current;
	t_stack		*temp;

	current = *stack;
	while (current->next != NULL)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
			{
				ft_putstr("Error\n");
				exit(0);
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

/*
** Returns the last element is a list
*/

t_stack		*lstend(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*
** Returns the length of the stack
*/

int			length(t_stack **stack)
{
	t_stack		*temp;
	int			count;

	count = 0;
	if (*stack == NULL)
		return (count);
	temp = *stack;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
