#include "push_swap.h"

void	ft_check_min_max(t_basik *stack)
{
	t_stack	*A;
	int		i;

	i = 1;
	A = stack->a;
	stack->max = -2147483648;
	stack->min = 2147483647;
	while (A->next)
	{
		i++;
		A = A->next;
	}
	A = stack->a;
	while (i)
	{
		if(A->val > stack->max)
			stack->max = A->val;
		if(A->val < stack->min)
			stack->min = A->val;
		A = A->next;
		i--;
	}
	return ;
}

void	ft_sort_utils(t_basik *stack, int i, t_stack *A)
{
	if (i != stack->min && i != stack->max)
	{
		A = A->next;
		if (A->val == stack->max)
			ft_rra(stack, 1);
		else
			ft_sa(stack, 1);
	}
	if (stack->a->val == stack->max)
	{
		A = A->next;
		if (A->val == stack->min)
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
	t_stack	*A;
	int		i;

	A = stack->a;
	i = A->val;
	ft_check_min_max(stack);
	ft_sort_utils(stack, i, A);
	if (i == stack->min)
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	return ;
}
