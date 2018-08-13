/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:19:20 by jmsimang          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:21 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Swaps both stack A and stack B.
*/

void		swap_stacks(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

/*
** Rotates both stack A and stack B.
*/

void		rotate_stacks(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

/*
** Reverse rotates both stack A and stack B.
*/

void		reverse_rotate_stacks(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

/*
** Checks if number is within INT bounds.
*/

long long	num_is_int(const char *str)
{
	long long	digit;
	long long	sign;

	digit = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	sign = ((*str == '-') ? -1 : 1);
	while (ft_isdigit(*str))
		digit = digit * 10 + (*str++ - '0');
	return (digit * sign);
}

/*
** Searches for the largest number on the stack and returns it.
*/

int			max(t_stack **stack)
{
	int			num;
	t_stack		*temp;

	temp = *stack;
	num = temp->value;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->value > num)
			num = temp->value;
	}
	return (num);
}
