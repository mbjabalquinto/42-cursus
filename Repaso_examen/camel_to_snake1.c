#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

void    camel_to_snake(char *str)
{
    int i;
    char c;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        if (is_upper(str[i]))
        {
            if (i > 0 && !is_space(str[i - 1]))
            {
                c = str[i] + 32;
                write(1, "_", 1);
            }
            else
                c = str[i];
        }
        else
            c = str[i];
        write(1, &c, 1);
        i++;
     }
}


int main(int argc, char **argv)
{
    if (argc == 2)
        camel_to_snake(argv[1]);
    write(1, "\n", 1);
    return (0);
}
