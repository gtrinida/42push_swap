#include "libft.h"

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
