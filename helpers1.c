/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:17:33 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/20 17:17:35 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Performs simple stack operations for stacks that are of size 3 or less.
*/

t_move		sort_mini(t_stack **stack)
{
	if (check_sorting(*stack))
		return (ok);
	else if (check_reverse_sorting(*stack) || (*stack)->value == max(stack))
		return (ra);
	else if ((*stack)->next->value == min(stack))
		return (sa);
	else
		return (rra);
}

/*
** Performs a quicksort given the stack size is less than or equal to 10 digits.
*/

t_move		sort_min(t_stack **stack_a, t_stack **stack_b)
{
	int			len;

	len = length(stack_a);
	if (check_sorting(*stack_a) && *stack_b == NULL)
		return (ok);
	if (check_sorting(*stack_a) && check_reverse_sorting(*stack_b) && *stack_b)
		return (pa);
	if (len == 3)
	{
		if (sort_mini(stack_a) == ok)
			return (pa);
		else
			return (sort_mini(stack_a));
	}
	if ((*stack_a)->value == min(stack_a))
		return (pb);
	else
		return (get_pos(min(stack_a), stack_a) <= (len / 2) ? ra : rra);
}

/*
** Performs a quicksort algorithm on the stacks A and B.
*/

t_move		q_sort(t_stack **s_a, t_stack **s_b, int pivot)
{
	if (get_move(s_a, s_b, pivot) < 0)
		return (rrr);
	else if (get_move(s_a, s_b, pivot) > 0)
		return (rr);
	else
	{
		if (pivot != (*s_a)->value)
			return (get_pos(pivot, s_a) <= (length(s_a) / 2) ? ra : rra);
		else
		{
			if (get_pos_right(pivot, s_b, 0) == 0)
				return (pb);
			else
				return (get_pos_right(pivot, s_b, 0) <= (length(s_b) / 2) ? rb :
					rrb);
		}
	}
}

/*
** Determins which sorting function to apply based on the number of arguments
** given to the program.
*/

t_move		operation(int size, t_stack **s_a, t_stack **s_b)
{
	int			pivot;

	pivot = 0;
	if (size == 2)
		return (check_sorting(*s_a) ? ok : sa);
	else if (size == 3)
		return (sort_mini(s_a));
	else if (size <= 10)
		return (sort_min(s_a, s_b));
	else
	{
		if (check_sorting(*s_a) && !*s_b)
			return (ok);
		else if (check_sorting(*s_a) && check_reverse_sorting(*s_b) && *s_b &&
			((*s_a)->value > (*s_b)->value))
			return (pa);
		else if (check_sorting(*s_a) && !check_reverse_sorting(*s_b) && *s_b &&
			(!*s_a || (*s_a)->value > max(s_b)))
			return (get_pos(min(s_b), s_b) < (length(s_b) / 2) ? rb : rrb);
		else
		{
			pivot = get_index(s_a, s_b);
			return (q_sort(s_a, s_b, pivot));
		}
	}
}
