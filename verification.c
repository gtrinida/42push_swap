#include "push_swap.h"
#include <stdio.h>

int	check_double(t_stack *A)
{
	t_stack *tmp;
	int		dublicate;
	
	tmp = A;
	dublicate = tmp->val;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (dublicate == tmp->val)
			return(0);
	}
	return (1);
}

void	ft_initialization(t_basik *basic)
{
	basic->a = NULL;
	basic->b = NULL;
	basic->max = -2147483648;
	basic->min = 2147483647;
}

int	ft_verification_third(char **av)
{	
	// t_stack *A;

	// A = stacks->a;
	if (check_int(av) == -1)
		return(-1);
	// if (!check_double(A))
	// 	return(-1);
	if (check_long(av) == -1)
		return(-1);
	return(1);	
}

int	ft_verification_second(char **argv, int *i, int j, t_basik *stacks)
{
	int		condition;
	char	**split;

	split = ft_split(argv[*i], ' ');
	while (split[j])
	{
		condition =	ft_verification_third(split);
		if (condition == -1)
		{
			write(1, "Error\n", 6);
			return(-1);
		}
		add_new_node(&(stacks->a), ft_atoi(split[j]));
		j++;
	}
	ft_strsfree(split);
	return (0);
}

int ft_verification(char **argv, t_basik *stacks)
{
	int condition;
	int i;
	int j;
	

	j = 0;
	i = 1;
	
	while (argv[i])
	{
		condition =	ft_verification_second(argv, &i, j, stacks);
		if (condition == -1)
			return (1);
		i++;
	}
	return 0;
}
