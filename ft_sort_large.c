#include "push_swap.h"

int	ft_up_or_down(int index, int len)
{
	return (index <= len / 2);
}

void	ft_final_sort_utils(t_basik *stack)
{
	int	len;
	int	index;
	int	direction;
	t_stack *A;

	A = stack->a;
	len = ft_check_values(stack);
	while (A)
	{
		if(A->val == stack->max)
		{
			index = A->index;
			break ;
		}
		A = A->next;
	}
	direction = ft_up_or_down(index, len);
	if (direction)
	{
		while (index)
		{
			ft_ra(stack);
			index--;
		}
		ft_ra(stack);
		ft_ra(stack);
	}
	else
	{
		len = len - index;
		len--;
		while (len)
		{
			ft_rra(stack);
			len--;
		}
		
	}
}

void	ft_final_sort(t_basik *stack, t_actions *info)
{
	int i;
	int	j;
	int len_a;
	int	len_b;

	i = info->index_b;
	j = info->index_a;
	len_a = ft_stack_len(stack, 1);
	len_b = ft_stack_len(stack, 2);
//	printf("index b is: %d\n", i);
//	printf("index a is: %d\n", j);
//	printf("direction A is: %d\n", info->way_a);
	if (info->way_b)
	{
		while (i)
		{
			ft_rb(stack);
			i--;
		}
	}
	if (!info->way_b)
	{
		while (i != len_b)
		{
			ft_rrb(stack);
			i++;
		}
	}
		i = info->index_b;
	if (info->way_a)
	{
		while (j)
		{
			ft_ra(stack);
			j--;
		}
	}
	if (!info->way_a)
	{
		while (j != len_a)
		{
			ft_rra(stack);
			j++;
		}
	}
	ft_pa(stack);
}

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
//	printf("Total steps: %d\n", tmp);
	if (tmp < info->steps) // Я убрал info->steps = tmp (понять что это было за условие и почему это пофиксилось)
	{
//		printf("A index: %d\nLen is: %d\n", a_index, len_a);
	//	info->steps = tmp;
		info->index_a = a_index;
		info->way_a = ft_up_or_down(a_index, len_a);
//		printf("A way is: %d\n", info->way_a);
		info->index_b = B->index;
		info->way_b = ft_up_or_down(B->index, len_b);
//		printf("Best B index is: %d\n", B->index);
	}
}

void	ft_optimal_put(t_basik *stack, t_stack *B, t_actions *info)
{
	t_stack *A;
	int		tmp;
	int		a_index;

	A = stack->a;
	// print(A);
	// print(B);
	tmp = 2147483647;
	A = stack->a;
//	printf("B val is:%d\n", B->val);
	while (A)
	{
	//	printf("%d > %d && %d < %d\n", tmp, A->val, B->val, A->val);
		if (tmp >= A->val && B->val < A->val)
		{
			tmp = A->val;
			a_index = A->index;
		}
		A = A->next;
	}
//	A = A->next;
//	printf("Optimal value: %d\n", tmp);
	ft_steps(stack, B, a_index, info);
}

void	ft_start_sort(t_basik *stack, t_actions *info)
{
	t_stack *B;
	int	len_b;

	B = stack->b;
	len_b = ft_stack_len(stack, 2);
	// print(stack->a);
	// print(B);
	// printf("New cycle\n");
	// printf("lenght b: %d\n", len_b);
	while (len_b)
	{
		ft_optimal_put(stack, B, info);
		B = B->next;
		len_b--;
	}
	ft_final_sort(stack, info);
	
}

void	ft_sort_large(t_basik *stack, int len, t_actions *info)
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
	while(stack->b) 
	{
		ft_get_index(stack);
		ft_start_sort(stack, info);
	}
	ft_final_sort_utils(stack);
}