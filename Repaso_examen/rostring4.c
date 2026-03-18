#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void    rostring(char *str)
{
    int i;
    int start;
    int end;

    i = 0;
    if (!str)
        return ;
    while (str[i] && is_space(str[i]))
        i++;
    start = i;
    while (str[i] && !is_space(str[i]))
        i++;
    end = i - 1;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (!str[i])
            break;
        while (str[i] && !is_space(str[i]))
        {    
            write(1, &str[i], 1);
            i++;
        }
        write(1, " ", 1);
    }
    while (start <= end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        rostring(argv[1]);
    write(1, "\n", 1);
    return (0);
}
