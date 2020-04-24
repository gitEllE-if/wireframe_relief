#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*begin;

	begin = str;
	while (*str)
		str++;
	return (str - begin);
}
