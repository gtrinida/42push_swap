#include "push_swap.h"
#include <stdio.h>

void	ft_strsfree(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int check_long(char **av)
{
	int overflow;
	int i;

	i = 0;
	overflow = 1;
	while (av[i]) 
	{
		ft_atoi_overflow(av[i], &overflow);
		if(overflow == -1)
			return(-1);
		i++;
	}
	return(1);
}

 // подучить и написать подобное 
int check_zero(const char *str)
{
	size_t i;
	int is_first;

	i = 0;
	is_first = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i])
	{
		if (!is_first && str[i] >= '1' && str[i] <= '9')
			return (1);
		if (str[i] >= '0')
		{
			is_first = 1;
		}
		if (is_first && str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (-1);
		i++;
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

int check_int_utils(char **av, int *i, int j)
{
	while (av[*i][j] == '\t' || av[*i][j] == ' ')
		j++;
	if(av[*i][j] == '-' || av[*i][j] == '+')
	{
		j++;
		if(av[*i][j] > '9' || av[*i][j] < '0')
			return(-1);
	}	
	while (av[*i][j] <= '9' && av[*i][j] >= '0')
		j++;	
	while (av[*i][j])
	{
		if(av[*i][j] != '\t' || av[*i][j] != ' ')
			return (-1);
		j++;
	}
	return(0);
}

int check_int(char **av)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	while (av[i])
	{
		check = check_zero(av[i]);
		if(check == -1)
			return (-1);
		check = check_int_utils(av, &i, j);
		if(check == -1)
			return (-1);
		i++;
	}
	return(1);
}

int check_double(char **av)
{
	int tmp;
	int next;
	int	i;
	int j;
	
	i = 1;
	j = 2;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		while (av[j])
		{
			next = ft_atoi(av[j]);
			if (tmp == next)
				return (-1);
			j++;
		}
		i++;
	}
	return(1);
}

int	ft_verification_third(char **av)
{	
	if (check_int(av) == -1)
		return(-1);
	// if (check_double(av) == -1)
	// 	return(-1);
	if (check_long(av) == -1)
		return(-1);
	return(1);	
}

int ft_verification_second(char **argv, int *i, int j)
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
		j++;
	}
	ft_strsfree(split);
	return (0);
}

int ft_verification(char **argv)
{
	int condition;
	int i;
	int j;
	

	j = 0;
	i = 1;
	
	while (argv[i])
	{
		condition =	ft_verification_second(argv, &i, j);
		if (condition == -1)
			return (1);
		i++;
	}
	return 0;
}
