#include "libft.h"

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
