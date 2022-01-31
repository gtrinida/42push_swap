#include "push_swap.h"

void ft_sort_utils(t_basik *stack, int i, t_stack *A)
{
	if (i != stack->min && i != stack->max)
	{
		A = A->next;
		if (A->val == stack->max)
			ft_rra(stack);
		else
			ft_sa(stack);
	}
	if (stack->a->val == stack->max)
	{
		A = A->next;
		if (A->val == stack->min)
			ft_ra(stack);
		else
		{
			ft_ra(stack);
			ft_sa(stack);
		}
	}
}

void	ft_sort(t_basik *stack)
{
	t_stack *A;
	int i;

	A = stack->a;
	i = A->val;
	
	ft_sort_utils(stack, i, A);
	
	if (i == stack->min)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	return;
}