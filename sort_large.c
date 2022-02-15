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
void	ft_steps(t_basik *stack, t_stack *B, int a_index, t_actions *info)
{
	int	len_a;
	int	len_b;
	int	tmp;

	len_a = ft_stack_len(stack, 1);
	len_b = ft_stack_len(stack, 2);
	tmp = ft_steps_utils(a_index, B->index, len_a, len_b);
	if (tmp < info->steps) 
	{
		info->steps = tmp;
		info->index_a = a_index;
		info->way_a = ft_up_or_down(a_index, len_a);
		info->index_b = B->index;
		info->way_b = ft_up_or_down(B->index, len_b);
	}
}

void	ft_optimal_put(t_basik *stack, t_stack *B, t_actions *info)
{
	t_stack	*A;
	int		tmp;
	int		a_index;

	A = stack->a;
	tmp = 2147483647;
	A = stack->a;
	while (A)
	{
		if (tmp >= A->val && B->val < A->val)
		{
			tmp = A->val;
			a_index = A->index;
		}
		A = A->next;
	}
	ft_steps(stack, B, a_index, info);
}

void	ft_start_sort(t_basik *stack, t_actions *info)
{
	t_stack	*B;
	int		len_b;

	B = stack->b;
	len_b = ft_stack_len(stack, 2);
	while (len_b)
	{
		ft_optimal_put(stack, B, info);
		B = B->next;
		len_b--;
	}
	ft_push_to_a(stack, info);
}

void	ft_sort_large(t_basik *stack, int len, t_actions *info)
{
	t_stack	**A;

	A = &(stack->a);
	while (len)
	{
		if ((*A)->val != stack->max && (*A)->val != stack->min)
			ft_pb(stack);
		else
			ft_ra(stack, 1);
		len--;
	}
	if ((*A)->val != stack->max)
		ft_sa(stack, 1);
	ft_pa(stack);
	while(stack->b) 
	{
		ft_get_index(stack);
		ft_action_initialization(info);
		ft_start_sort(stack, info);
	}
	ft_sort_a(stack);
}
