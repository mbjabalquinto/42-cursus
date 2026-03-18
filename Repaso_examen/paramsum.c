#include <unistd.h>

void    ft_putnbr(int num)
{
    char n;

    if (num >= 10)
        ft_putnbr(num / 10);
    n = (num % 10) + '0';
    write(1, &n, 1);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc > 1)
    {
        argc--;
        ft_putnbr(argc);
    }
    else
        write(1, "0", 1);
    write(1, "\n", 1);
    return (0);
}
