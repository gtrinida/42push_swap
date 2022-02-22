#include "push_swap.h"
#include "libft.h"

int	ft_up_or_down(int index, int len)
{
	return (index <= len / 2);
}

void	ft_sort_a_utils(int index, t_basik *stack, int len)
{
	int	direction;

	direction = ft_up_or_down(index, len);
	if (direction)
	{
		while (index)
		{
			ft_ra(stack, 1);
			index--;
		}
	}
	else
	{
		len = len - index;
		while (len)
		{
			ft_rra(stack, 1);
			len--;
		}
	}
}

void	ft_sort_a(t_basik *stack)
{
	int		len;
	int		index;
	t_stack	*A;

	ft_get_index(stack);
	A = stack->a;
	len = ft_check_values(stack);
	while (A)
	{
		if(A->val == stack->min)
		{
			index = A->index;
			break ;
		}
		A = A->next;
	}
	ft_sort_a_utils(index, stack, len);
}
void	ft_push_to_a_utils(t_basik *stack, t_actions *info)
{
	int	len_a;
	int	j;

	j = info->index_a;
	len_a = ft_stack_len(stack, 1);
	if (info->way_a)
	{
		while (j)
		{
			ft_ra(stack, 1);
			j--;
		}
	}
	if (!info->way_a)
	{
		while (j != len_a)
		{
			ft_rra(stack, 1);
			j++;
		}
	}
	ft_pa(stack);
}

void	ft_push_to_a(t_basik *stack, t_actions *info)
{
	int	i;
	int	len_b;

	i = info->index_b;
	len_b = ft_stack_len(stack, 2);
	if (info->way_b)
	{
		while (i)
		{
			ft_rb(stack, 1);
			i--;
		}
	}
	if (!info->way_b)
	{
		while (i != len_b)
		{
			ft_rrb(stack, 1);
			i++;
		}
	}
	ft_push_to_a_utils(stack, info);
}
