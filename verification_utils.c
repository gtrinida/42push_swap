/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:25:59 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:25:59 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strsfree(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	check_long(char **av)
{
	int	overflow;
	int	i;

	i = 0;
	overflow = 1;
	while (av[i])
	{
		ft_atoi_overflow(av[i], &overflow);
		if (overflow == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_zero(const char *str)
{
	size_t	i;
	int		is_first;

	i = 0;
	is_first = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i])
	{
		if (!is_first && str[i] >= '1' && str[i] <= '9')
			return (1);
		if (str[i] >= '0')
		{
			is_first = 1;
		}
		if (is_first && str[i] == '0'
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	check_int_utils(char **av, int *i, int j)
{
	while (av[*i][j] == '\t' || av[*i][j] == ' ')
		j++;
	if (av[*i][j] == '-' || av[*i][j] == '+')
	{
		j++;
		if (av[*i][j] > '9' || av[*i][j] < '0')
			return (-1);
	}	
	while (av[*i][j] <= '9' && av[*i][j] >= '0')
		j++;
	while (av[*i][j])
	{
		if (av[*i][j] != '\t' || av[*i][j] != ' ')
			return (-1);
		j++;
	}
	return (0);
}

int	check_int(char **av)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (av[i])
	{
		check = check_zero(av[i]);
		if (check == -1)
			return (-1);
		check = check_int_utils(av, &i, j);
		if (check == -1)
			return (-1);
		i++;
	}
	return (1);
}
