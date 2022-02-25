#include "libft.h"

void	ft_bzero(void *arr, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)arr;
	while (i < len)
	{
		buf[i] = 0;
		i++;
	}
	arr = buf;
}
