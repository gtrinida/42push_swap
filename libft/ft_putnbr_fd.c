/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:39:29 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:39:30 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n)
{
	long long int	number;
	int				count;

	count = 0;
	number = n;
	if (number < 0)
	{
		number = number * (-1);
		count++;
	}
	if (number == 0)
		count++;
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	int				len;
	char			num[10000];
	long long int	number;

	number = n;
	i = 0;
	len = ft_nlen(n);
	num[len--] = '\0';
	if (number < 0)
	{
		num[0] = '-';
		number = number * (-1);
	}
	else if (number == 0)
		num[0] = '0';
	while (number > 0)
	{
		num[len--] = '0' + (number % 10);
		number = number / 10;
	}
	while (num[i] != '\0')
	{
		write(fd, &num[i++], 1);
	}
}
