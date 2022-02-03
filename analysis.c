#include "push_swap.h"

int ft_is_sorted(t_basik *stack)
{
	t_stack *A;
	int		value;

	A = stack->a;
	while (A->next)
	{
		value = A->val;
		A = A->next;
		if (value > A->val)
			return (0);
	}
	A = stack->a;
	return (1);
}

int ft_check_values(t_basik *stack) 
{
	t_stack *A;
	int		i;
	int		n;

	i = 1;
	A = stack->a;
	while (A->next)
	{
		i++;
		A = A->next;
	}
	A = stack->a;
	n = i;
	while (i)
	{
		if(A->val > stack->max)
			stack->max = A->val;
		if(A->val < stack->min)
			stack->min = A->val;
		A = A->next;
		i--;
	}
	return (n);
}

void	ft_analysis(t_basik *stack)
{
	int len;

	len = ft_check_values(stack);
	if (ft_is_sorted(stack) == 1)
	{
		printf("it's sorted\n");
		return ;
	}
	if (ft_is_sorted(stack) == 0)
	{
		printf("Doesn't sorted\n");
		if (len == 2)
			ft_sa(stack);
		if (len == 3)
			ft_sort_three(stack);
		if (len == 4 || len == 5)
			ft_sort_four_five(stack);
		if (len > 5)
			ft_sort_large(stack, len);
	}
	return;
}