#include <unistd.h>

void    ft_union(char *str, char *s)
{
    int chars[256];
    int i;

    i = 0;
    while (i < 256)
    {
        chars[i] = 0;
        i++;
    }
    i = 0;
    while (str[i])
    {
        if (chars[(unsigned int)str[i]] == 0)
        {
            write(1, &str[i], 1);
            chars[(unsigned int) str[i]] = 1;
        }
        i++;
    }
    i = 0;
    while (s[i])
    {
        if (chars[(unsigned int) s[i]] == 0)
        {
            write(1, &s[i], 1);
            chars[(unsigned int)s[i]] = 1;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}
