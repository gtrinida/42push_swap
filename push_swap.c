#include "push_swap.h"
#include "libft.h"
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

void free_stacks(t_basik *stacks)
{
	t_stack	*tmp;
	int		i;
	int		len_a;
	int		len_b;
	len_a = ft_stack_len(stacks, 1);
	len_b = ft_stack_len(stacks, 2);
	i = 0;
	while(i < len_a)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		free(tmp);
		i++;
	}
	i = 0;
	while(i < len_b)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		free(tmp);
		i++;
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
		free_stacks(stacks);
	}
	free(stacks);
	return (0);
}
