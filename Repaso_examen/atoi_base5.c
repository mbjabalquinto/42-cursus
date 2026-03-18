#include <stdio.h>

int is_number(char c)
{
    return (c >= '0' && c <= '9');
}

int is_upper(char c)
{
    return (c >= 'A' && c <= 'F'); 
}

int is_lower(char c)
{
    return (c >= 'a' && c <= 'f');
}

int get_value(char c)
{
    if (is_number(c))
        return (c - '0');
    else if (is_upper(c))
        return ((c - 'A') + 10);
    else if (is_lower(c))
        return ((c - 'a') + 10);
    return (-1);
}

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int is_negative;
    int value;
    int number;

    i = 0;
    number = 0;
    value = 0;
    is_negative = 1;
    while (str[i] && is_space(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            is_negative = -1;
        i++;
    }
    while (str[i])
    {
        value = get_value(str[i]);
        if (value == -1 || value >= str_base)
            break;    
        number = number * str_base + value;
        i++;
    }
    return (number * is_negative);
}

int main(void)
{
    int number;

    number = ft_atoi_base("af", 16);
    printf("%d\n", number);
    return (0);
}
