#include "push_swap.h"

int	ft_middle(int len)
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

int ft_optimal_index(t_basik *stack)
{
	t_stack *B;
	int	tmp;
	int	len;
	int	index;

	B = stack->b;
	index = B->index;
	len = ft_stack_len(stack, 2);
	tmp = B->total;
	while (len)
	{
		if(tmp > B->total)
		{
			tmp = B->total;
			index = B->index;
		}
		B = B->next;
		len--;
	}
	B = stack->b;
	return(index);
}

int	ft_steps_B(t_stack *B, int len)
{
	int		middle;

	middle	= ft_middle(len);
	len = len + 1;
	if (B->index > middle)
		return(len - B->index);
	else
		return(B->index + 1);
}

int ft_steps_to_A_final(t_basik *stack, int index)
{
	t_stack *A;
	int		len;
	int		middle;
	A = stack->a;

	len = ft_stack_len(stack, 1);
	middle = ft_middle(len);
	ft_up_or_down(A, middle);
	if (index > middle)
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

int	ft_steps_to_A(t_basik *stack, t_stack *B)
{
	t_stack *A;
	int		index;
	int		steps;

	A = stack->a;
	while (A->next)
	{
		A->larger = 0;
		A = A->next;
	}
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
//	printf("steps in A: %d\n", steps);
	return(steps);
}

void	ft_steps_to_a_for_all(t_basik *stack)
{
	t_stack *B;
	int		len_b;
	int 	len;
	B = stack->b;
	len_b = ft_stack_len(stack, 2);
	while (len_b)
	{	
		B->total = ft_steps_to_A(stack, B);

		B = B->next;
		len_b--;
	}
	B = stack->b;
	len_b = ft_stack_len(stack, 2);
	len = len_b;
	while(len_b)
	{
		B->total += ft_steps_B(B, len);	
		B = B->next;
		len_b--;
	}
}

void	ft_get_index_utils(t_basik *stack)
{
	t_stack *B;
	int 	len;
	int		i;

	i = 0;	
	B = stack->b;
	len = ft_stack_len(stack, 2);
	while (len)
	{
		B->index = i;
		i++;
		len--;
		B = B->next;
	}
}

void	ft_get_index(t_basik *stack)
{
	t_stack *A;
	int 	len;
	int		i;

	i = 0;	
	A = stack->a;
	len = ft_stack_len(stack, 1);
	while (len)
	{
		A->index = i;
		i++;
		len--;
		A = A->next;
	}
	A = stack->a;
	ft_get_index_utils(stack);
}

void	ft_b(t_basik *stack)
{
	int middle;
	int len_b;

	t_stack *B = stack->b;
	int i = 0;
	len_b = ft_stack_len(stack, 2);
	middle = ft_middle(len_b);
	ft_get_index(stack);
	ft_up_or_down(stack->b, middle);
	ft_steps_to_a_for_all(stack);

	while (len_b)
	{
		printf("Comands for %d index is: %d\n", i, B->total);
		len_b--;
		B = B->next;
		i++;
	}
	

}

void	ft_sort_large(t_basik *stack, int len)
{
	t_stack **A;
	int index;
	index = 0;
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
		index = ft_optimal_index(stack);
		printf("Optimal index is %d\n", index);
	}

}
