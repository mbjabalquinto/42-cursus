#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	i = 0;
	while (line[i])
	{
		write(0, &line[i], 1);
		i++;
	}
	return (0);
}