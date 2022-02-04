#include "push_swap.h"

int	ft_opimal_way(int len)
{
	int way;

	way = len / 2;
	return (way);
}

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

void ft_up_or_down(t_stack *stack, int optimal_way)
{
	if (stack->index > optimal_way)
	{
		stack->direction = -1;
	}
	else //вверх
		stack->direction = 1;
}

int	ft_steps_B(t_basik *stack)
{
	t_stack *B;
	int		len;
	int		way;
	
	B = stack->b;
	len = ft_stack_len(stack, 2);
	way	= ft_opimal_way(len);
	len = len + 1;
	if (B->index > way)
		return(len - B->index);
	else
		return(B->index + 1);
}


int ft_steps_to_A_final(t_basik *stack, int index)
{
	t_stack *A;
	int		len;
	int		way;
	A = stack->a;

	len = ft_stack_len(stack, 1);
	way = ft_opimal_way(len);
	ft_up_or_down(A, way);
	if (index > way)
		return(len - index);
	else
		return(index);
}

int	ft_steps_to_A_utils(t_basik *stack)
{
	t_stack	*A;
	int		flag;
	int		temp;
	
	flag = 0;
	A = stack->a;

	while (A->next)
	{
		if(A->larger == 1 && !flag)
		{
			temp = A->val;
			flag = 1;
		}
		if(A->larger == 1 && temp > A->val)
			temp = A->val;
		A = A->next;
	}
	A = stack->a;
	while (A->next)
	{
		if (A->val == temp)
			return(A->index);
		A = A->next;
	}
	return (-1);
}

int	ft_steps_to_A(t_basik *stack)
{
	t_stack *B;
	t_stack *A;
	int		index;
	int		steps;
	B = stack->b;
	A = stack->a;
	while (A->next)
	{
		if (B->val < A->val)
			A->larger = 1;
		A = A->next;
	}
	A = stack->a;
	index = ft_steps_to_A_utils(stack);
	steps =	ft_steps_to_A_final(stack, index);
//	printf("%d\n", steps);
	return(steps);
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

void	ft_b(t_basik *stack)
{
	int optimal_way;
	int len;
	int stepsA;
	int	stepsB;
	len = ft_stack_len(stack, 2);
	optimal_way = ft_opimal_way(len);
	ft_get_index(stack);
	ft_up_or_down(stack->b, optimal_way);
	stepsA = ft_steps_to_A(stack);
	stepsB = ft_steps_B(stack);
	printf("Comands needs in A: %d\n", stepsA);
	printf("Comands needs in B: %d\n", stepsB);
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
