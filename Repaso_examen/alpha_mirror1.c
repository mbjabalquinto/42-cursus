#include <unistd.h>

void alfa_mirror(char *str)
{
    int i;
    char n;
    char c;

    i = 0;
    n = 0;
    while (str[i])
    {
        c = str[i];
        if (str[i] >= 'a' && str[i] <= 'z')
        {    
            n = str[i] - 'a';
            c = 'z' - n;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            n = str[i] - 'A';
            c = 'Z' - n;
        }
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        alfa_mirror(argv[1]);
    write (1, "\n", 1);
    return (0);
}
