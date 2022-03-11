/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:15:40 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/03 14:15:40 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_argv(char **argv)
{
	int	i;
	int	j;
	int	valid;

	valid = 1;
	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				valid = 1;
				break ;
			}
			j++;
		}
		if (valid == 0)
			return (0);
		valid = 0;
		i++;
	}
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
		if (!ft_valid_argv(argv))
		{
			write(1, "Error\n", 6);
			free_stacks(stacks);
			free(stacks);
			return (-1);
		}
		ft_analysis(stacks);
		free_stacks(stacks);
	}
	free(stacks);
	return (0);
}
