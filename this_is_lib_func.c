#include "push_swap.h"

void	*ft_memset(void *arr, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	buf = (unsigned char *)arr;
	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	return (arr = buf);
}


static int	ft_get_size(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (start < ft_strlen(s))
		while (s[i + start] != '\0' && i < len)
			i++;
	return (i + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_get_size(s, start, len)));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{
		while (s[i + start] != '\0' && i < len)
		{
			str[i] = s[i + start];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}


size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t sym, size_t onesymsize)
{
	void	*mem;

	mem = malloc(sym * onesymsize);
	if (mem)
	{
		return (ft_memset(mem, '\0', sym * onesymsize));
	}
	return (NULL);
}

char	*ft_strrchr(const char *string, int c)
{
	int	i;

	i = ft_strlen(string);
	while (i > -1)
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i--;
	}
	return (NULL);
}

char	**ft_free(char	**strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	strings = 0;
	return (strings);
}

int	ft_sublen(char *s, int start, char end)
{
	int	total;

	total = 0;
	while (s[start] != '\0' && s[start] != end)
	{
		total++;
		start++;
	}
	return (total);
}

int	ft_strnum(char const *s, char c)
{
	int	i;
	int	sub_start;
	int	total;

	total = 0;
	i = 0;
	sub_start = 0;
	while (s[i] != '\0')
	{	
		if (s[i] != c && sub_start == 0)
		{
			sub_start = 1;
			total++;
		}
		if (s[i] == c && sub_start == 1)
			sub_start = 0;
		i++;
	}
	return (total);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		sub_start;
	char	**strings;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	sub_start = 0;
	strings = ft_calloc((ft_strnum(s, c) + 1), sizeof(char *));
	while (strings && s[i] != '\0')
	{
		if (s[i] != c && sub_start == 0)
		{
			sub_start = 1;
			strings[j] = ft_substr(s, i, ft_sublen((char *) s, i, c));
			if (!strings[j++])
				return (ft_free(strings));
		}
		if (s[i] == c && sub_start == 1)
			sub_start = 0;
		i++;
	}
	return (strings);
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
