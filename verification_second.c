/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:35:43 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/13 01:08:06 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verification_third(char **av)
{	
	if (check_int(av) == -1)
		return (-1);
	if (check_long(av) == -1)
		return (-1);
	return (1);
}

int	ft_verification_utils(int condition, t_basik *stacks)
{
	condition = check_double(stacks->a);
	if (condition == -1)
	{
		write(2, "Error\n", 6);
		free_stacks(stacks);
		return (-1);
	}
	return (0);
}

int	ft_verification_second(char **argv, int *i, int j, t_basik *stacks)
{
	int		condition;
	char	**split;

	split = ft_split(argv[*i], ' ');
	while (split[j])
	{		
		condition = ft_verification_third(split);
		if (condition == -1)
		{
			write(2, "Error\n", 6);
			free_stacks(stacks);
			ft_strsfree(split);
			return (-1);
		}
		add_new_node(&(stacks->a), ft_atoi(split[j]));
		j++;
	}
	ft_strsfree(split);
	condition = ft_verification_utils(condition, stacks);
	if (condition == -1)
		return (-1);
	return (0);
}
