#include "libft.h"

size_t	ft_sstrlen(char **sstr)
{
	size_t	i;

	i = 0;
	while (sstr[i])
		i++;
	return (i);
}