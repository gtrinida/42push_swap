/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:06 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:38:09 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *arr, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)arr;
	while (i < len)
	{
		buf[i] = 0;
		i++;
	}
	arr = buf;
}
