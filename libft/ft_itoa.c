/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:42 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:38:43 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int long	number;
	int			i;

	i = 0;
	number = n;
	if (number < 0)
	{
		number = number * (-1);
		i++;
	}
	else if (number == 0)
		i++;
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int long	number;
	int			len;
	char		*nbr;

	number = n;
	len = ft_len(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len--] = '\0';
	if (number < 0)
	{
		nbr[0] = '-';
		number = number * (-1);
	}
	else if (number == 0)
		nbr[len] = '0';
	while (number > 0)
	{
		nbr[len--] = '0' + (number % 10);
		number = number / 10;
	}
	return (nbr);
}
