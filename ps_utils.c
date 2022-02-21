#include "push_swap.h"

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
