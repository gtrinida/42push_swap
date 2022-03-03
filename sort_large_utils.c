/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:22:50 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 15:22:50 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_middle(int len)
{
	int	way;

	way = len / 2;
	return (way);
}

int	ft_stack_len(t_basik *stack, int d)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = stack->a;
	b = stack->b;
	if (d == 1)
	{
		while (a)
		{
			a = a->next;
			i++;
		}
	}
	if (d == 2)
	{
		while (b)
		{
			b = b->next;
			i++;
		}
	}
	return (i);
}

void	ft_get_index_utils(t_basik *stack)
{
	t_stack	*b;
	int		len;
	int		i;

	i = 0;
	b = stack->b;
	len = ft_stack_len(stack, 2);
	while (len)
	{
		b->index = i;
		i++;
		len--;
		b = b->next;
	}
}

void	ft_get_index(t_basik *stack)
{
	t_stack	*a;
	int		len;
	int		i;

	i = 0;
	a = stack->a;
	len = ft_stack_len(stack, 1);
	while (len)
	{
		a->index = i;
		i++;
		len--;
		a = a->next;
	}
	a = stack->a;
	ft_get_index_utils(stack);
}
