#include <unistd.h>
#include <string.h>
#include "libft.h"

int	main()
{
	char	str1[20] = "Cake_is";
	char	str2[] = "_a_Lie";
	// size_t	buf = ft_strlen(str1) + ft_strlen(str2) + 1;
	size_t	buf = 3;

	// ft_strlcat(str1, str2, buf);
	strlcat(str1, str2, buf);
	write(1, str1, ft_strlen(str1));
	return (1);
}
