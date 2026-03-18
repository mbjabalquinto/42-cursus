#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    char *s;
    int len;
    int i;

    i = 0;
    s = NULL;
    if (!str)
        return (NULL);
    len = ft_strlen(str);
    s = malloc((len + 1) * sizeof(char));
    if (!s)
        return (NULL);
    while (str[i])
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}

int main(void)
{
    char *s;

    s = ft_strdup("Hola como estas");
    printf("%s\n", s);
    free(s);
    return (0);
}
