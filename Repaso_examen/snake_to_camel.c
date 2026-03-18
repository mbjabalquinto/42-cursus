#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

void    snake_to_camel(char *str)
{
    int i;
    int len;
    int upper;
    int snake;
    char c;

    i = 0;
    upper = 0;
    snake = 0;
    if (!str)
        return ;
    len = ft_strlen(str) - 1;
    while (str[i])
    {
        c = str[i];
        if (i > 0 && c == '_')
        {
            if (i < len && is_lower(str[i + 1]) && is_lower(str[i - 1]))
                snake = 1;
        }
        if (upper == 1)
        {
            c -=32;
            write(1, &c, 1);
            upper = 0;
        }
        else if (snake == 0)
            write(1, &c, 1);
        else
            upper = 1;
        snake = 0;
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
        snake_to_camel(argv[1]);
    write(1, "\n", 1);
    return (0);
}
