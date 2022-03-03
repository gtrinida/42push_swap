/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:01 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:38:03 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nonspace(char c)
{
	return (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ');
}

int	ft_checklong(int result, int term, int sign)
{
	long long int	res;

	res = result;
	res = result * 10 + term;
	if (sign == 1)
	{
		if (res > 2147483647)
			return (-1);
	}
	if (sign == -1)
	{
		if (res < -2147483648)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ft_nonspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (ft_checklong(result, (str[i] - '0'), sign) != 1)
			return (ft_checklong(result, (str[i] - '0'), sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
