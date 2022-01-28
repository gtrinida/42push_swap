#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void	free_stack(t_stack **A)
{
	t_stack *tmp;

	while ((*A)->next)
	{	
		tmp = *A;
		A = (*A)->next;
		free (tmp);
	}
}

void	print(t_stack *A)
{
	if(!A)
	{
		printf("Nothing\n");
		return ;
	}
	while (A->next)
	{
		printf("%d ", A->val);
		A = A->next;
	}
	printf("%d \n", A->val);
}


int main(int argc, char **argv)
{
	t_basik *stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_basik));
	if (!stacks)
		return (0);
	ft_initialization(stacks);
	if(!ft_verification(argv, stacks))
	{
		ft_sa(stacks);
		ft_pb(stacks);
		ft_pb(stacks);
		ft_pb(stacks);
		ft_rr(stacks);
		ft_rrr(stacks);
		ft_sa(stacks);
		ft_pa(stacks);
		ft_pa(stacks);
		ft_pa(stacks);
		print(stacks->a);
		print(stacks->b);
		free_stack(&stacks->a);
	}	

	return (0);
}

// int main(int argc, char **arvg)
// {
// 	t_basik *stacks;

// 	int tmp;
// 	int i;
// 	stacks = malloc(sizeof(t_basik));
// 	if (!stacks)
// 		return 0;
// 	stacks->a = NULL;
// 	stacks->b = NULL;
// 	i = 1;

// 	while (i < argc)
// 	{
// 		tmp = ft_atoi(arvg[i]);
// 		add_new_node(&(stacks->a), tmp);
// 		i++;
// 	}
// 	ft_ra(stacks);
// 	print(stacks->a);
// 	print(stacks->b);
// 	free_stack(&stacks->a);
// 	return (0);
// }