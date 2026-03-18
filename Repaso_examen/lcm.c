#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int number;

    if (a == 0 || b == 0)
        return (0);
    if (a >= b)
        number = a;
    else
        number = b;
    while (1)
    {
        if (number % a == 0 && number % b == 0)
            return (number);
        number++;
    }
}

int main(void)
{
    unsigned int num;

    num = lcm(14, 21);
    printf("%d\n", num);
    return (0);
}
