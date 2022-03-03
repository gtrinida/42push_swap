/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:22 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:38:23 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	return ((character >= 48 && character <= 57)
		|| (character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122));
}
