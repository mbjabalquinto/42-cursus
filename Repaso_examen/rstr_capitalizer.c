#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

char *lower(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);

}

void    str_capitalizer(char *str)
{
    int i;

    i = 0;
    if (!str)
        return ;
    str = lower(str);
    while(str[i])
    {
        while (str[i] && is_space(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
        if (!str[i])
            break;
        while (str[i] && !is_space(str[i]))
        {    
            if (!is_space(str[i + 1]) && str[i + 1]!= '\0')
                write (1, &str[i], 1);
            i++;
        }
        i--;
        if (str[i] >= 'a' && str[i] <= 'z')
        {
           str[i] -= 32;
           write(1, &str[i], 1);
           i++;
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    int i;
    
    i = 1;
    if (argc > 1)
    {
        while (i <= argc)
        {
            str_capitalizer(argv[i]);
            if (i < argc)
                write(1, "\n", 1);
            i++;
        }
    }
    else
        write (1, "\n", 1);
    return (0);
}
