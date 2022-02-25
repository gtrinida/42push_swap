#include "libft.h"

void	*ft_memcpy(void *buf, const void *source, size_t len)
{
	char		*b;
	const char	*s;

	if ((buf == source) || len == 0)
		return (buf);
	if (!buf && !source)
		return (0);
	b = (char *)buf;
	s = (const char *) source;
	while (len--)
	{
		b[len] = s[len];
	}
	return (buf);
}
