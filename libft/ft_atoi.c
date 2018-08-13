/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 07:55:11 by jmsimang          #+#    #+#             */
/*   Updated: 2017/12/16 07:55:15 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' ||
		c == '\f' || c == '\n')
		return (1);
	return (0);
}

int		ft_check_result(int i, long long res, int sign)
{
	if ((res > INT_MAX && sign == 1) || ((res * -1) < INT_MIN && sign == -1))
		return (-2);
	if ((i > 19 || res > 9223372036854775807) && sign == 1)
		return (-1);
	if ((i > 19 || res > 9223372036854775807) && sign == -1)
		return (0);
	return (1);
}

int		ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		res = (res * 10) + (*str++ - '0');
		i++;
	}
	if (ft_check_result(i, res, sign) != 1)
		return (ft_check_result(i, res, sign));
	return ((int)res * sign);
}
