#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
//#include "C:\Users\ilya9\OneDrive\Desktop\Coding\Actual\push_swap\libft\libft.h"

typedef struct s_stack
{
	int		val;
	void	*next;
}t_stack;

typedef	struct s_basic
{
	t_stack *a;
	t_stack *b;

}t_basik;

void	ft_sa(t_basik *stack);
void	ft_sb(t_basik *stack);
void	ft_ss(t_basik *stacks);
void	ft_ra(t_basik *stack);
void	ft_rb(t_basik *stack);
void	ft_rr(t_basik *stacks);
void	ft_rra(t_basik *stack);
void	ft_rrb(t_basik *stack);
void	ft_rrr(t_basik *stacks);
void	ft_pb(t_basik *stacks);
void	ft_pa(t_basik *stacks);
void	add_new_node(t_stack **head, int val);
void	add_new_node_reverse(t_stack **head, int val);
void	down_stack(t_stack **stack);
void	swap_hg(t_stack **stack);
t_stack	*create_node(int val);
void	up_stack(t_stack **stack);

#endif