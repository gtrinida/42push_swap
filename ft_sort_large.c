#include "push_swap.h"

int	ft_up_or_down(int index, int len)
{
	int	middle;

	middle = len / 2;
	if (index <= middle)
		return (1); //наверх
	else
		return (0);
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
	printf("Total steps: %d\n", tmp);
	if (tmp < info->steps)
	{
		info->steps = tmp;
		info->index_a = a_index;
		info->way_a = ft_up_or_down(a_index, len_a);
		info->index_b = B->index;
		info->way_b = ft_up_or_down(B->index, len_b);
		printf("Best B index is: %d\n", B->index);
	}
}

void	ft_optimal_put(t_basik *stack, t_stack *B, t_actions *info) //Вернет количество команд для каждого элемента
{
	t_stack *A;
	int		tmp;
	int		flag;
	int		a_index;

	A = stack->a;
	tmp = B->val;
	flag = 0;
	while (A->next)
	{
		if (tmp < A->val && !flag)
		{
			tmp = A->val;
			flag = 1;
			a_index = A->index;
		}
		if (B->val < A->val)
		{
			if (tmp > A->val)
			{
				tmp = A->val;
				a_index = A->index;
			}
		}
		A = A->next;
	}
	A = A->next;
//	printf("Optimal value: %d\n", tmp);
	ft_steps(stack, B, a_index, info);
}

void	ft_start_sort(t_basik *stack, t_actions *info)
{
	t_stack *B;
	int	len_b;

	B = stack->b;
	len_b = ft_stack_len(stack, 2);
	
	while (len_b)
	{
		ft_optimal_put(stack, B, info);
		B = B->next;
		len_b--;
	}
	
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
	if(stack->b)
	{
		ft_get_index(stack);
		ft_start_sort(stack, info);
	}

}