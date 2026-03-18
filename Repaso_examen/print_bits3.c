#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int     i;
    char    bits;
    
    i = 7;
    while (i >= 0)
    {
        bits = (octet >> i) &1;
        bits = bits + '0';
        write(1, &bits, 1);
        i--;
    }
}
