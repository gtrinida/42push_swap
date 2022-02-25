#include "libft.h"

void	*ft_memmove(void *buf, const void *source, size_t len)
{
	char	*b;
	char	*s;

	if (!buf && !source)
		return (0);
	b = (char *)buf;
	s = (char *)source;
	if (buf > source)
	{
		while (len--)
			b[len] = s[len];
	}
	else
		while (len--)
			*b++ = *s++;
	return (buf);
}
