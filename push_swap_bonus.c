#include "push_swap_bonus.h"

int	ft_is_it_sorted(t_basik *stacks)
{
	t_stack	*a;
	int		value;

	a = stacks->a;
	while (a->next)
	{
		value = a->val;
		a = a->next;
		if (value > a->val)
			return (0);
	}
	if(stacks->b)
		return(0);
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while ((*a)->next)
	{
		tmp = *a;
		a = (*a)->next;
		free (tmp);
	}
}

void	free_stacks(t_basik *stacks)
{
	t_stack	*tmp;
	int		i;
	int		len_a;
	int		len_b;

	len_a = ft_stack_len(stacks, 1);
	len_b = ft_stack_len(stacks, 2);
	i = 0;
	while (i < len_a)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		free(tmp);
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		free(tmp);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_basik	*stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_basik));
	if (!stacks)
		return (0);
	ft_initialization(stacks);
	if (!ft_verification(argv, stacks))
	{
		if(!ft_is_sorted(stacks))
		{
			ft_analysis(stacks);
			if (!ft_is_it_sorted(stacks))
				write(1, "KO\n", 3);
			else if (ft_is_it_sorted(stacks) == 1)
				write(1, "OK\n", 3);
		}
		free_stacks(stacks);
	}
	free(stacks);
	return (0);
}
