#include <unistd.h>

void    inter(char *str, char *s)
{
    int chars[256];
    int i;
    int j;

    i = 0;
    while (i <= 255)
    {
        chars[i] = 0;
        i++;
    }
    i = 0;
    while (str[i])
    {
        j = 0;
        while (s[j])
        {
            if (chars[(unsigned int)str[i]] == 1)
                break;
            else if (str[i] == s[j] && chars[(unsigned int)str[i]] == 0)
            {
                write(1, &str[i], 1);
                chars[(unsigned int)str[i]] = 1;
                break;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}
