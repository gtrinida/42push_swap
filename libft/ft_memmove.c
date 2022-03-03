/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:39:07 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:39:08 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf, const void *source, size_t len)
{
	char	*b;
	char	*s;

	if (!buf && !source)
		return (0);
	b = (char *)buf;
	s = (char *)source;
	if (buf > source)
	{
		while (len--)
			b[len] = s[len];
	}
	else
		while (len--)
			*b++ = *s++;
	return (buf);
}
