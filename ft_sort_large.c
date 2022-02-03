#include "push_swap.h"

int ft_stack_len(t_basik *stack, int d)
{
	t_stack *A;
	t_stack *B;
	int i;

	i = 0;
	A = stack->a;
	B = stack->b;
	if (d == 1)
	{
		while (A)
		{
			A = A->next;
			i++;
		}
	}
	if (d == 2)
	{
		while (B)
		{
			B = B->next;
			i++;
		}
	}
	return (i);
}

void	ft_get_index(t_basik *stack)
{
	t_stack *A;
	t_stack *B;
	int 	len;
	int		i;

	i = 0;	
	A = stack->a;
	B = stack->b;
	len = ft_stack_len(stack, 1);
	while (len)
	{
		A->index = i;
		i++;
		len--;
		A = A->next;
	}
	A = stack->a;
	i = 0;
	len = ft_stack_len(stack, 2);
	while (len)
	{
		B->index = i;
		i++;
		len--;
		B = B->next;
	}
	B = stack->b;
}

int	ft_opimal_way(int len)
{
	int way;

	way = len / 2;
	way = way + 1;
	return (way);
}


void	ft_b(t_basik *stack)
{
	int optimal_way;
	int len;

	len = ft_stack_len(stack, 2);
	optimal_way = ft_opimal_way(len);
	ft_get_index(stack);
	printf("optimal way: %d\n", optimal_way);
}
void	ft_sort_large(t_basik *stack, int len)
{
	t_stack **A;

	A = &(stack->a);
	while (len)
	{
		if ((*A)->val != stack->max && (*A)->val != stack->min)
			ft_pb(stack);
		else
			ft_ra(stack);
		len--;
	}
	if ((*A)->val != stack->max)
		ft_sa(stack);
	ft_pa(stack);
	if(stack->b)
	{
		ft_b(stack);
	}
}