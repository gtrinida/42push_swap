#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str = ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}
