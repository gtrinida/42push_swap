/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:41:03 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:41:04 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (start < ft_strlen(s))
		while (s[i + start] != '\0' && i < len)
			i++;
	return (i + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_get_size(s, start, len)));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{
		while (s[i + start] != '\0' && i < len)
		{
			str[i] = s[i + start];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
