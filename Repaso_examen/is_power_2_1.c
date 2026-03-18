int is_power_of_2(unsigned int n)
{
    int i;
    int cont;

    i = 31;
    cont = 0;
    if (n == 0)
        return (0);
    while (i >= 0)
    {
        if ((n >> i) &1 == 1)
            cont++;
        if (cont > 1)
            return (0);
        i--;
    }
    return (1);
}
