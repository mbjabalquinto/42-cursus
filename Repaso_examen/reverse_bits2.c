#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char bits;
	i = 0;
	bits = 0;
	while (i <= 7)
	{
		bits = ((octet >> i) & 1) | bits << 1;
		i++;
	}
	return (bits);
}

int	main(void)
{
	unsigned char bits;
	char bit;
	int i;

	i = 7;
	bits = reverse_bits((unsigned char)65);
	while (i >= 0)
	{
		bit = (bits >> i) & 1;
		bit = bit + '0';
		write(1, &bit, 1);
		i--;
	}
	return (0);
}
