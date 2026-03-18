#include <stdlib.h>
#include <stdio.h>

void    pgcd(unsigned int a, unsigned int b)
{
    unsigned int num;

    if (a == 0 || b == 0)
        printf("0");
    if (a <= b)
        num = a;
    else
        num = b;
    while (num > 0)
    {
        if (a % num == 0 && b % num == 0)
        {
            printf("%d", num);
            break;
        }
        num--;
    }
}

int main(int argc, char **argv)
{
    unsigned int a;
    unsigned int b;

    if (argc == 3)
    {
        a = (unsigned int)atoi(argv[1]);
        b = (unsigned int)atoi(argv[2]);
        pgcd(a, b);
    }
    printf("\n");
    return (0);
}
