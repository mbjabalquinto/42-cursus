#include <unistd.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_space(char c)
{
    return(c == ' ' || c == '\t');
}

void    rev_wstr(char *str)
{
    int len;
    int start;
    int end;
    int first_word;

    first_word = 1;
    if (!str)
        return ;
    len = ft_strlen(str) - 1;
    while (len >= 0)
    {
        while (len >= 0 && is_space(str[len]))
            len--;
        if (len < 0)
            break;
        end = len;
        while (len >= 0 && !is_space(str[len]))
            len--;
        start = len + 1;
        if (first_word == 0)
            write(1, " ", 1);
        while (start <= end)
        {
            write(1, &str[start], 1);
            start++;
        }
        first_word = 0;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}
