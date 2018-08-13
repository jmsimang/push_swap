/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:19:29 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:31 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Reads and performs stack operation instruction for CHECKER.
*/

void		instructions(t_stack **a, t_stack **b, char *args)
{
	if (!ft_strcmp(args, "sa"))
		swap(a);
	else if (!ft_strcmp(args, "sb"))
		swap(b);
	else if (!ft_strcmp(args, "ss"))
		swap_stacks(a, b);
	else if (!ft_strcmp(args, "pa"))
		push(a, b);
	else if (!ft_strcmp(args, "pb"))
		push(b, a);
	else if (!ft_strcmp(args, "ra"))
		rotate(a);
	else if (!ft_strcmp(args, "rb"))
		rotate(b);
	else if (!ft_strcmp(args, "rr"))
		rotate_stacks(a, b);
	else if (!ft_strcmp(args, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(args, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(args, "rrr"))
		reverse_rotate_stacks(a, b);
	else if (write(1, "Error\n", 6))
		exit(0);
}

/*
** Reverse rotates a given stack.
*/

void		reverse_rotate(t_stack **stack)
{
	t_stack		*last;
	t_stack		*temp;

	last = *stack;
	if (*stack && (*stack)->next)
	{
		while (last->next != NULL)
		{
			temp = last;
			last = last->next;
		}
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	return ;
}

/*
** Rotates rotates a given stack.
*/

void		rotate(t_stack **stack)
{
	t_stack		*current;
	t_stack		*temp;

	temp = *stack;
	if (temp != NULL && temp->next != NULL)
	{
		*stack = (*stack)->next;
		temp->next = NULL;
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
	return ;
}

/*
** Pushes an element from stack_b to stack_a and vice versa.
*/

void		push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*temp;

	temp = *stack_b;
	if (*stack_b != NULL)
	{
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	return ;
}

/*
** Swaps a given stack's first and second element.
*/

void		swap(t_stack **stack)
{
	int			digit;

	digit = 0;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		digit = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = digit;
	}
}
