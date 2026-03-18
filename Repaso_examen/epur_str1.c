#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void    epur_str(char *str)
{
    int i;
    int first_word;

    i = 0;
    first_word = 1;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (!str[i])
            break;
        if (first_word == 0)
            write(1, " ", 1);
        while (str[i] && !is_space(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
        first_word = 0:
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        epur_str(argv[1]);
    write(1, " ", 1);
    return (0);
}
