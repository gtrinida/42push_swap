/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:39:14 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:39:15 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	buf = (unsigned char *)arr;
	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	return (arr = buf);
}
