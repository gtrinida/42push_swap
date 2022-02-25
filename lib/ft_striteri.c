#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))

{
	size_t	i;

	i = 0;
	while (s && *s)
	{
		f(i, s);
		i++;
		s++;
	}
}
