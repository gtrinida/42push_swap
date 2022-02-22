#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	ft_sa(t_basik *stack, int print)
{
	swap_hg(&(stack->a));
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_basik *stack, int print)
{
	swap_hg(&(stack->b));
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ra(t_basik *stack, int print)
{
	up_stack(&(stack->a));
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_basik *stack, int print)
{
	up_stack(&(stack->b));
	if (print)
		write(1, "rb\n", 3);
}
