/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:20:13 by gtrinida          #+#    #+#             */
/*   Updated: 2022/02/26 14:20:13 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_initialization(t_actions *info)
{
	info->index_a = 0;
	info->index_b = 0;
	info->way_a = 0;
	info->way_b = 0;
	info->steps = 2147483647;
}

int	ft_is_sorted(t_basik *stack)
{
	t_stack	*a;
	int		value;

	a = stack->a;
	while (a->next)
	{
		value = a->val;
		a = a->next;
		if (value > a->val)
			return (0);
	}
	a = stack->a;
	return (1);
}

int	ft_check_values(t_basik *stack)
{
	t_stack	*a;
	int		i;
	int		n;

	i = 1;
	a = stack->a;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	a = stack->a;
	n = i;
	while (i)
	{
		if (a->val > stack->max)
			stack->max = a->val;
		if (a->val < stack->min)
			stack->min = a->val;
		a = a->next;
		i--;
	}
	return (n);
}

void	ft_analysis(t_basik *stack)
{
	t_actions	*info;
	int			len;

	len = ft_check_values(stack);
	if (ft_is_sorted(stack) == 1)
		return ;
	if (ft_is_sorted(stack) == 0)
	{
		if (len == 2)
			ft_sa(stack, 1);
		if (len == 3)
			ft_sort_three(stack);
		if (len == 4 || len == 5)
			ft_sort_four_five(stack);
		if (len > 5)
		{
			info = malloc(sizeof(t_actions));
			if (!info)
				return ;
			ft_action_initialization(info);
			ft_sort_large(stack, len, info);
			free(info);
		}
	}
	return ;
}
