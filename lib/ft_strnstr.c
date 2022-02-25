#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	size;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	size = ft_strlen(needle);
	i = 0;
	while (haystack[i] != '\0' && n >= size)
	{
		if (*(haystack + i) == *needle)
			if (ft_memcmp(haystack + i, needle, size) == 0)
				return ((char *)haystack + i);
		i++;
		n--;
	}
	return (0);
}
