/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_first.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:09:54 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 14:09:54 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_hg(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	if (tmp->next)
	{
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	ft_sa(t_basik *stack, int print)
{
	swap_hg(&(stack->a));
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_basik *stack, int print)
{
	swap_hg(&(stack->b));
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ra(t_basik *stack, int print)
{
	up_stack(&(stack->a));
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_basik *stack, int print)
{
	up_stack(&(stack->b));
	if (print)
		write(1, "rb\n", 3);
}
