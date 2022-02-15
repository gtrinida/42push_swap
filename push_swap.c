#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void	free_stack(t_stack **A)
{
	t_stack	*tmp;

	while((*A)->next)
	{
		tmp = *A;
		A = (*A)->next;
		free (tmp);
	}
}

int main(int argc, char **argv)
{
	t_basik	*stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_basik));
	if (!stacks)
		return (0);
	ft_initialization(stacks);
	if(!ft_verification(argv, stacks))
	{
		ft_analysis(stacks);
		free_stack(&stacks->a);
	}
	return (0);
}
