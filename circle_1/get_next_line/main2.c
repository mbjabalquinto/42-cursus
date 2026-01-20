#include "get_next_line.h"

int	main(void)
{
	char *line;

	line = get_next_line(42);
	printf("%s", line);
	return (0);
}
