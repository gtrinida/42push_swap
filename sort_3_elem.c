/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:22:20 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 14:22:20 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_min_max(t_basik *stack)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = stack->a;
	stack->max = -2147483648;
	stack->min = 2147483647;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	a = stack->a;
	while (i)
	{
		if (a->val > stack->max)
			stack->max = a->val;
		if (a->val < stack->min)
			stack->min = a->val;
		a = a->next;
		i--;
	}
	return ;
}

void	ft_sort_utils(t_basik *stack, int i, t_stack *a)
{
	if (i != stack->min && i != stack->max)
	{
		a = a->next;
		if (a->val == stack->max)
			ft_rra(stack, 1);
		else
			ft_sa(stack, 1);
	}
	if (stack->a->val == stack->max)
	{
		a = a->next;
		if (a->val == stack->min)
			ft_ra(stack, 1);
		else
		{
			ft_ra(stack, 1);
			ft_sa(stack, 1);
		}
	}
}

void	ft_sort_three(t_basik *stack)
{
	t_stack	*a;
	int		i;

	a = stack->a;
	i = a->val;
	ft_check_min_max(stack);
	ft_sort_utils(stack, i, a);
	if (i == stack->min)
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	return ;
}
