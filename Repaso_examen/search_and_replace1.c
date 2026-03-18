#include <unistd.h>

void    search_and_replace(char *str, char *s1, char *s2)
{
    int i;
    char c;

    i = 0;
    if (s1[1] || s2[1])
        return ;
    while (str[i])
    {
        if (str[i] == s1[0])
            c = s2[0];
        else
            c = str[i];
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
        search_and_replace(argv[1], argv[2], argv[3]);
    write(1, "\n", 1);
    return (0);
}
