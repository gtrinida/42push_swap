/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:09:17 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 14:09:17 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_space(int c)
{
	return ((char)c == '\t' || (char)c == '\v' || (char)c == '\f'
		|| (char)c == '\r' || (char)c == '\n' || (char)c == ' ');
}

int	ft_overflow(int result, int term, int sign)
{
	long long int	res;

	res = result;
	res = (res * 10) + term;
	res = res * sign;
	if (res > +2147483647)
		return (1);
	else if (res < -2147483648)
		return (1);
	return (0);
}

int	ft_atoi_overflow(const char *str, int *overflow)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] != '\0' && ft_space(str[i]))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (ft_overflow(result, (str[i] - '0'), sign))
			return (*overflow = *overflow - 2);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
