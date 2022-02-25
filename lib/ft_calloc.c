#include "libft.h"

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
