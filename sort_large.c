/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:24:34 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:24:34 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_steps_utils(int a_index, int b_index, int len_a, int len_b)
{
	int	steps;

	if (ft_up_or_down(a_index, len_a))
		steps = a_index;
	if (!ft_up_or_down(a_index, len_a))
		steps = len_a - a_index;
	if (ft_up_or_down(b_index, len_b))
		steps += b_index + 1;
	if (!ft_up_or_down(b_index, len_b))
		steps += len_b - b_index + 1;
	return (steps);
}

void	ft_steps(t_basik *stack, t_stack *b, int a_index, t_actions *info)
{
	int	len_a;
	int	len_b;
	int	tmp;

	len_a = ft_stack_len(stack, 1);
	len_b = ft_stack_len(stack, 2);
	tmp = ft_steps_utils(a_index, b->index, len_a, len_b);
	if (tmp < info->steps)
	{
		info->steps = tmp;
		info->index_a = a_index;
		info->way_a = ft_up_or_down(a_index, len_a);
		info->index_b = b->index;
		info->way_b = ft_up_or_down(b->index, len_b);
	}
}

void	ft_optimal_put(t_basik *stack, t_stack *b, t_actions *info)
{
	t_stack	*a;
	int		tmp;
	int		a_index;

	a = stack->a;
	tmp = 2147483647;
	a = stack->a;
	while (a)
	{
		if (tmp >= a->val && b->val < a->val)
		{
			tmp = a->val;
			a_index = a->index;
		}
		a = a->next;
	}
	ft_steps(stack, b, a_index, info);
}

void	ft_start_sort(t_basik *stack, t_actions *info)
{
	t_stack	*b;
	int		len_b;

	b = stack->b;
	len_b = ft_stack_len(stack, 2);
	while (len_b)
	{
		ft_optimal_put(stack, b, info);
		b = b->next;
		len_b--;
	}
	ft_push_to_a(stack, info);
}

void	ft_sort_large(t_basik *stack, int len, t_actions *info)
{
	t_stack	**a;

	a = &(stack->a);
	while (len)
	{
		if ((*a)->val != stack->max && (*a)->val != stack->min)
			ft_pb(stack);
		else
			ft_ra(stack, 1);
		len--;
	}
	if ((*a)->val != stack->max)
		ft_sa(stack, 1);
	ft_pa(stack);
	while (stack->b)
	{
		ft_get_index(stack);
		ft_action_initialization(info);
		ft_start_sort(stack, info);
	}
	ft_sort_a(stack);
}
