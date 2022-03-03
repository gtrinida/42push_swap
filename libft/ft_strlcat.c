/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:40:17 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:40:18 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *buf, const char *source, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	buf_len;
	size_t	source_len;

	x = 0;
	buf_len = ft_strlen(buf);
	source_len = ft_strlen(source);
	y = buf_len;
	if (size == 0)
		return (source_len);
	if (buf_len > size)
		return (source_len + size);
	while (source[x] && (buf_len + x) < size - 1)
		buf[y++] = source[x++];
	if (y > size)
		buf[--y] = '\0';
	else
		buf[y] = '\0';
	return (source_len + buf_len);
}
