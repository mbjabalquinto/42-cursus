#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_atoi(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] && is_space(str[i]))
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (num);
}

void    print_hex(unsigned int num)
{
    char hex[16] = "0123456789abcdef";
    int index;

    index = 0;
    if (num >= 16)
        print_hex(num / 16);
    index = num % 16;
    write(1, &hex[index], 1);
}

int main(int argc, char **argv)
{
    unsigned int num;

    num = 0;
    if (argc == 2)
    {
        num = (unsigned int)ft_atoi(argv[1]);
        print_hex(num);
    }
    write(1, "\n", 1);
    return (0);
}
