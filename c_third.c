#include "push_swap.h"

void	ft_ss(t_basik *stacks)
{
	write(1, "ss\n", 3);
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
}

void	ft_rr(t_basik *stacks)
{
	write(1, "rr\n", 3);
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
}

void	ft_rrr(t_basik *stacks)
{
	write(1, "rrr\n", 3);
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
}
