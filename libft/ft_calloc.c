/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:17 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:38:18 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t sym, size_t onesymsize)
{
	void	*mem;

	mem = malloc(sym * onesymsize);
	if (mem)
	{
		return (ft_memset(mem, '\0', sym * onesymsize));
	}
	return (NULL);
}
