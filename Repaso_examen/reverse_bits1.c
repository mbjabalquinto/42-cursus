unsigned char   reverse_bits(unsigned char octet)
{
    unsigned char   bits;
    int i;
    int j;

    bits = 0;
    i = 7;
    while (i >= 0)
    {
        bits = (bits << 1) | ((octet >> i) &1);
        i--;
    }
    return (bits);
}
