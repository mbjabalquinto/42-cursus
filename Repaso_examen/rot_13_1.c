#include <unistd.h>

void    rot_13(char *str)
{
    char c;
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
           if (str[i] <= 'm')
                c = str[i] + 13;
           else
               c = str[i] - 13;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (str[i] <= 'M')
                c = str[i] + 13;
            else
                c = str[i] - 13;
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
        rot_13(argv[1]);
    write(1, "\n", 1);
    return (0);
}
