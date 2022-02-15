#include "push_swap.h"

void	ft_pb(t_basik *stacks)
{
	t_stack	*tmp;

	if (stacks->a == NULL)
		return ;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	add_new_node_reverse(&(stacks->b), tmp->val);
	write(1, "pb\n", 3);
	free(tmp);
}

void	ft_pa(t_basik *stacks)
{
	t_stack	*tmp;

	if (stacks->b == NULL)
		return ;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	add_new_node_reverse(&(stacks->a), tmp->val);
	write(1, "pa\n", 3);
	free(tmp);
}

void	ft_rra(t_basik *stack, int print)
{
	down_stack(&(stack->a));
	if (print)	
		write(1, "rra\n", 4);
}

void	ft_rrb(t_basik *stack, int print)
{
	down_stack(&(stack->b));
	if (print)
		write(1, "rrb\n", 4);
}
