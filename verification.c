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

int	ft_nonspace(char c)
{
	return (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ');
}

int	ft_checklong(int result, int term, int sign)
{
	long long int	res;

	res = result;
	res = result * 10 + term;
	if (sign == 1)
	{
		if (res > 2147483647)
			return (-1);
	}
	if (sign == -1)
	{
		if (res < -2147483648)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ft_nonspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (ft_checklong(result, (str[i] - '0'), sign) != 1)
			return (ft_checklong(result, (str[i] - '0'), sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int character)
{
	return (character >= '0' && character <= '9');
}

static int	ft_issign(int c)
{
	return ((char)c == '-' || (char)c == '+');
}

static int	ft_iswhitespace(int c)
{
	return ((char)c == '\t' || (char)c == '\v' || (char)c == '\f'
		|| (char)c == '\r' || (char)c == '\n' || (char)c == ' ');
}

static	int	ft_checkoverflow(int res, int term, int sign)
{
	long long int	result;

	result = res;
	result = (result * 10) + term;
	result = result * sign;
	if (result > +2147483647)
		return (-1);
	else if (result < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi_overflow(const char *str, int *overflow)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] != '\0' && ft_iswhitespace(str[i]))
		i++;
	if (str[i] != '\0' && ft_issign(str[i]))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (ft_checkoverflow(res, (str[i] - '0'), sign) != 1)
			return(*overflow = *overflow - 2);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
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

int check_int(char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[i])
	{
		
		while (av[i][j] == '\t' || av[i][j] == ' ')
			j++;
		if(av[i][j] == '-' || av[i][j] == '+')
		{
			j++;
			if(av[i][j] > '9' || av[i][j] < '0')
				return(-1);
		}	
		while (av[i][j] <= '9' && av[i][j] >= '0')
			j++;	
		while (av[i][j])
		{
			if(av[i][j] != '\t' || av[i][j] != ' ')
				return (-1);
			j++;
		}
		j = 0;
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

int	ft_verification(char **av)
{	
	if (check_int(av) == -1)
		return(-1);
	// if (check_double(av) == -1)
	// 	return(-1);
	if (check_long(av) == -1)
		return(-1);
	return(1);	
}

int main(int argc, char **argv)
{
	int condition;
	int i;
	int j;
	char **split;

	j = 0;
	i = 1;
	
	if (argc < 2)
		return (0);
	while (argv[i])
	{	
		split = ft_split(argv[i], ' ');

		while (split[j])
		{
			condition =	ft_verification(split);
			if (condition == -1)
			{
				printf("Error\n");
				return(-1);
			}
			j++;
		}
		ft_strsfree(split);
		j = 0;
		i++;
	}
	printf("Nice\n");
	return 0;
}
