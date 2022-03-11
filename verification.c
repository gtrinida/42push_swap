/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:29:35 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:29:35 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack *A)
{
	t_stack	*tmp;
	t_stack	*temp;
	int		dublicate;

	temp = A;
	if (!temp)
		return (-1);
	while (temp->next)
	{
		tmp = temp;
		dublicate = temp->val;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (dublicate == tmp->val)
				return (-1);
		}
		temp = temp->next;
	}
	return (1);
}

void	ft_initialization(t_basik *basic)
{
	basic->a = NULL;
	basic->b = NULL;
	basic->max = -2147483648;
	basic->min = 2147483647;
}

int	ft_verification(char **argv, t_basik *stacks)
{
	int	condition;
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		condition = ft_verification_second(argv, &i, j, stacks);
		if (condition == -1)
			return (-1);
		i++;
	}
	return (0);
}
