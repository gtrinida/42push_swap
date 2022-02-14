#include "push_swap.h"
#include <stdio.h>

void	ft_sa(t_basik *stack)
{
	swap_hg(&(stack->a));
	write(1, "sa\n", 3);
}

void	ft_sb(t_basik *stack)
{
	swap_hg(&(stack->b));
	write(1, "sb\n", 3);
}

void	ft_ra(t_basik *stack)
{
	up_stack(&(stack->a));
	write(1, "ra\n", 3);
}

void	ft_rb(t_basik *stack)
{
	up_stack(&(stack->b));
	write(1, "rb\n", 3);
}
