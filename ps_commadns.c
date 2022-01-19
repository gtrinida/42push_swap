#include "push_swap.h"
#include <stdio.h>

void	ft_sa(t_stack **A)
{
	swap_hg(A);
}

void	ft_sb(t_stack **B)
{
	swap_hg(B);
}

// void	ft_ss(t_basik **stacks)
// {
// 	ft_sa((*stacks)->a);
// 	ft_sb((*stacks)->b);
// }


void	ft_ra(t_stack **A)
{
	up_stack(A);
}

void	ft_rb(t_stack **B)
{
	up_stack(B);
}

void	ft_rra(t_stack **A)
{
	go_down(A);
}

void	ft_rrb(t_stack **B)
{
	go_down(B);
}