#include <unistd.h>

void    wdmatch(char *s1, char *s2)
{
    int i;
    int j;
    int finded;

    i = 0;
    j = 0;
    finded = 0;
    if (!s1 && !s2)
        return ;
    while (s2[j]) 
    {
        if (s1[i] && s1[i] == s2[j])
        {
            i++;
            if (!s1[i])
            {
                finded = 1;
                break;
            }    
            j++;
        }
        else
            j++;
     }
    if (finded == 1)
    {
        i = 0;
        while (s1[i])
        {
            write(1, &s1[i], 1);
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        wdmatch(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}
