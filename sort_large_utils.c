#include "push_swap.h"
#include "libft.h"

int	ft_middle(int len)
{
	int	way;

	way = len / 2;
	return (way);
}

int	ft_stack_len(t_basik *stack, int d)
{
	t_stack	*A;
	t_stack	*B;
	int		i;

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
