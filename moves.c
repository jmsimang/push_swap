/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:55:00 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/20 16:55:01 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Returns the index position of a number in the right (B) stack.
*/

int			get_pos_right(int n, t_stack **stack, int i)
{
	int			j;
	int			sorted;

	j = 0;
	sorted = check_reverse_sorting(*stack);
	if (length(stack) == 1 || length(stack) == 0)
		return (i);
	else if (sorted && (n > (*stack)->value || n < lstend(*stack)->value))
	{
		while (j++ < i)
			reverse_rotate(stack);
		return (i);
	}
	else if (n > (*stack)->value && n < lstend(*stack)->value)
	{
		while (j++ < i)
			reverse_rotate(stack);
		return (i);
	}
	else
	{
		rotate(stack);
		return (get_pos_right(n, stack, i + 1));
	}
}

/*
** Returns the index position of a number in a stack.
*/

int			get_pos(int n, t_stack **stack)
{
	t_stack		*temp;
	int			i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->value == n)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

/*
** Determines the pivot needed for QSort to work and indicates whether to start
** sorting the left or the right stack first.
*/

int			get_move(t_stack **s_a, t_stack **s_b, int n)
{
	int			high;
	int			low;
	int			mid;
	int			midplus;

	high = MAX(get_pos(n, s_a), get_pos_right(n, s_b, 0));
	low = MAX(length(s_a) - get_pos(n, s_a) + 1,
		length(s_b) - get_pos_right(n, s_b, 0) + 1);
	mid = get_pos(n, s_a) + length(s_b) - get_pos_right(n, s_b, 0) + 1;
	midplus = length(s_a) - get_pos(n, s_a) + 1 + get_pos_right(n, s_b, 0);
	if (get_pos(n, s_a) == 0 || get_pos_right(n, s_b, 0) == 0)
		return (0);
	else if (high < low && high < MIN(mid, midplus))
		return (1);
	else if (low < high && low < MIN(mid, midplus))
		return (-1);
	else
		return (0);
}

/*
** Returns the number of steps needed to reach a number in a stack.
*/

int			get_steps(t_stack **s_a, t_stack **s_b, int n)
{
	int			high;
	int			low;
	int			mid;
	int			midplus;

	high = MAX(get_pos(n, s_a), get_pos_right(n, s_b, 0));
	low = MAX(length(s_a) - get_pos(n, s_a) + 1,
		length(s_b) - get_pos_right(n, s_b, 0) + 1);
	mid = get_pos(n, s_a) + length(s_b) - get_pos_right(n, s_b, 0) + 1;
	midplus = length(s_a) - get_pos(n, s_a) + 1 + get_pos_right(n, s_b, 0);
	if (high < low && high < MIN(mid, midplus))
		return (high);
	else if (low < high && low < MIN(mid, midplus))
		return (low);
	else
		return (MIN(mid, midplus));
}

/*
** Determines what the min and max values in the B stack are and then checks for
** the index at which to find the highest number in the A stack and then returns
** it.
*/

int			get_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*temp;
	int			top;
	int			min_steps;

	top = (*stack_a)->value;
	if (*stack_b)
	{
		min_steps = get_steps(stack_a, stack_b, (*stack_a)->value);
		top = (*stack_a)->value;
		temp = (*stack_a)->next;
		if (temp)
		{
			while (temp)
			{
				if (min_steps > get_steps(stack_a, stack_b, temp->value))
				{
					min_steps = get_steps(stack_a, stack_b, temp->value);
					top = temp->value;
				}
				temp = temp->next;
			}
		}
	}
	return (top);
}
