#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	int		s_len;
	char	*str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
