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
	t_actions *info;
	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_basik));
	if (!stacks)
		return (0);
	info = malloc(sizeof(t_actions)); // сменить ей место иницилизации только на то место где будет
	// 5+ символов
	if (!info)
		return (0);
	ft_initialization(stacks, info);
	if(!ft_verification(argv, stacks))
	{
		ft_analysis(stacks, info);
		// printf("stacks min: %d\n", stacks->min);
		// printf("stacks max: %d\n", stacks->max);
		print(stacks->a);
		print(stacks->b);
		free_stack(&stacks->a);
	}	

	return (0);
}
