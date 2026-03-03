#include <stdlib.h>

typedef struct  s_point
{
	int	x;
	int	y;	
}	t_point;

char **area;

char	**make_area(char **zone)
{

}

int	main(void)
{
	typedef struct  s_point
{
	return (zone);
}

void	print_tab(char **area)
{

}

void	flood_fill(char **area, t_point size, t_point begin)
{

}

int	main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}


