/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:40:49 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:40:50 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	size;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	size = ft_strlen(needle);
	i = 0;
	while (haystack[i] != '\0' && n >= size)
	{
		if (*(haystack + i) == *needle)
			if (ft_memcmp(haystack + i, needle, size) == 0)
				return ((char *)haystack + i);
		i++;
		n--;
	}
	return (0);
}
