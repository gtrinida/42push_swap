#include "push_swap.h"

void ft_sort_final(t_basik *stack)
{
	t_stack *B;
	int	val;

	B = stack->b;
	val = B->val;
	B = B->next;
	if (B->val > val)
	{
		ft_pa(stack);
		ft_pa(stack);
		ft_ra(stack);
	}
	if(B->val < val)
	{
		ft_pa(stack);
		ft_ra(stack);
		ft_pa(stack);
	}
	return ;
}

void push_min_max(t_basik *stack, t_stack **A, int flag)
{
	if ((*A)->val == stack->max)
	{
		flag = 1;
		ft_pb(stack);
	}	
	while ((*A)->val != stack->max && !flag)
		ft_ra(stack);
	if (!flag)
		ft_pb(stack);

	flag = 0;
	if ((*A)->val == stack->min)
	{
		flag = 1;
		ft_pb(stack);
	}	
	while ((*A)->val != stack->min && !flag)
		ft_ra(stack);
	if (!flag)
		ft_pb(stack);
	return ;
}

void	ft_sort_four_five(t_basik *stack)
{
	t_stack **A;
	int flag;
	int len;

	flag = 0;
	A = &(stack->a);
	push_min_max(stack, A, flag);
	if (!ft_is_sorted(stack))
	{
		len = ft_check_values(stack);
		if (len == 3)
			ft_sort_three(stack);
		if (len == 2)
			ft_sa(stack);
	}	
	ft_sort_final(stack);
}

