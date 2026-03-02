#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
}

int	main(void)
{
	unsigned char bits;
	int	i;
	char bit;

	i = 7;
	bits = swap_bits((unsigned char)1);
	while (i >= 0)
	{
		bit = (bits >> i) & 1;
		bit = bit + '0';
		write(1, &bit, 1);
		i--;
	}
	return (0);
}
