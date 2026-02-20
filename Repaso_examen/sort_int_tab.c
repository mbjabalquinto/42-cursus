#include <stdio.h>
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int num;

	i = 0;
	num = 0;
	is_negative = 1;

	while (str[i] && is_space(str[i])) 
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * is_negative);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int temp;
	unsigned int i;
	unsigned int j;

	i = 0;
	temp =  0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	unsigned int i;
	unsigned int size;
	int	*tab;

	i = 1;
	size = 0;
	tab = NULL;
	if (argc > 1)
	{
		tab = malloc((argc - 1) * sizeof(int));
		if (!tab)
			return (1);
		while (argc > 1)
		{
			tab[size] = ft_atoi(argv[i]);
			i++;
			size++;
			argc--;
		}
		sort_int_tab(tab, size);
	}
	free(tab);
	return (0);

}
