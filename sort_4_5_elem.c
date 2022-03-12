/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:25:02 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 14:25:02 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_final(t_basik *stack)
{
	t_stack	*b;
	int		val;

	b = stack->b;
	val = b->val;
	b = b->next;
	if (b->val > val)
	{
		ft_pa(stack);
		ft_pa(stack);
		ft_ra(stack, 1);
	}
	else
	{
		ft_pa(stack);
		ft_ra(stack, 1);
		ft_pa(stack);
	}
	return ;
}

void	push_min_max(t_basik *stack, t_stack **a, int len)
{
	// if ((*a)->val == stack->max)
	// {
	// 	flag = 1;
	// 	ft_pb(stack);
	// }	
	// while ((*a)->val != stack->max && !flag)
	// 	ft_ra(stack, 1);
	// if (!flag)
	// 	ft_pb(stack);
	// flag = 0;
	// if ((*a)->val == stack->min)
	// {
	// 	flag = 1;
	// 	ft_pb(stack);
	// }	
	// while ((*a)->val != stack->min && !flag)
	// 	ft_ra(stack, 1);
	// if (!flag)
	// 	ft_pb(stack);
	// return ;
	while (len)
	{
		if ((*a)->val != stack->max && (*a)->val != stack->min)
			ft_ra(stack, 1);
		else
			ft_pb(stack);
		len--;
	}
}

void	ft_sort_four_five(t_basik *stack)
{
	t_stack	**a;
	int		len;

	a = &(stack->a);
	len = ft_stack_len(stack, 1);
	push_min_max(stack, a, len);
	if (!ft_is_sorted(stack))
	{
		len = ft_check_values(stack);
		if (len == 3)
			ft_sort_three(stack);
		if (len == 2)
			ft_sa(stack, 1);
	}	
	ft_sort_final(stack);
}
