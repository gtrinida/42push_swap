#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

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

void	add_new_node(t_stack **head, int val);
void	ft_ra(t_stack **A);
void	ft_sa(t_stack **A);
void	ft_sb(t_stack **B);
void	swap_hg(t_stack **stuck);
t_stack	*create_node(int val);
void	up_stack(t_stack **stack);
void	ft_rb(t_stack **B);
void	ft_rra(t_stack **A);
void	ft_rrb(t_stack **B);
void	go_down(t_stack **stack);

#endif