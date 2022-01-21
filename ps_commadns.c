#include "push_swap.h"
#include <stdio.h>

void	ft_sa(t_basik *stack)
{
	swap_hg(&(stack->a));
}

void	ft_sb(t_basik *stack)
{
	swap_hg(&(stack->b));
}

void	ft_ss(t_basik *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}

void	ft_ra(t_basik *stack)
{
	up_stack(&(stack->a));
}

void	ft_rb(t_basik *stack)
{
	up_stack(&(stack->b));
}
void	ft_rr(t_basik *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
}

void	ft_rra(t_basik *stack)
{
	down_stack(&(stack->a));
}

void	ft_rrb(t_basik *stack)
{
	down_stack(&(stack->b));
}

void	ft_rrr(t_basik *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
}

void	ft_pb(t_basik *stacks)
{
	t_stack *tmp;
	int		val;
	if (stacks->a == NULL)
		return ;
	val = stacks->a->val;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	add_new_node_reverse(&(stacks->b), tmp->val);
	free(tmp);
}

void	ft_pa(t_basik *stacks)
{
	t_stack *tmp;
	int		val;
	if (stacks->b == NULL)
		return ;
	val = stacks->b->val;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	add_new_node_reverse(&(stacks->a), tmp->val);
	free(tmp);
}

