/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:39:54 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:39:54 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char	**strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	strings = 0;
	return (strings);
}

int	ft_sublen(char *s, int start, char end)
{
	int	total;

	total = 0;
	while (s[start] != '\0' && s[start] != end)
	{
		total++;
		start++;
	}
	return (total);
}

int	ft_strnum(char const *s, char c)
{
	int	i;
	int	sub_start;
	int	total;

	total = 0;
	i = 0;
	sub_start = 0;
	while (s[i] != '\0')
	{	
		if (s[i] != c && sub_start == 0)
		{
			sub_start = 1;
			total++;
		}
		if (s[i] == c && sub_start == 1)
			sub_start = 0;
		i++;
	}
	return (total);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		sub_start;
	char	**strings;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	sub_start = 0;
	strings = ft_calloc((ft_strnum(s, c) + 1), sizeof(char *));
	while (strings && s[i] != '\0')
	{
		if (s[i] != c && sub_start == 0)
		{
			sub_start = 1;
			strings[j] = ft_substr(s, i, ft_sublen((char *) s, i, c));
			if (!strings[j++])
				return (ft_free(strings));
		}
		if (s[i] == c && sub_start == 1)
			sub_start = 0;
		i++;
	}
	return (strings);
}
