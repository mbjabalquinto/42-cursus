#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i) & 1;
		bit = bit + '0';
		write(1, &bit, 1);
		i--;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_bits((unsigned)argv[1][0]);
	return (0);
}
