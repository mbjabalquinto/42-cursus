#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	int	i;
	int	bit;
	int	cont;

	cont = 0;
	i = 7;
	while (i >= 0)
	{
		bit = (n >> i) & 1;
		if (bit == 1)
			cont++;
		i--;
	}
	if (cont == 1)
		return (1);
	return (0);
}

int main(void)
{
	int	i;
	i = is_power_of_2((unsigned int)0);
	printf("%d\n", i); 
	return (0);
}
