char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		sign;
	char	*str;

	num = n;
	sign = (num < 0);
	if (num < 0)
		num = -num;
	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	str = malloc(len + sign + 1);
	if (!str)
		return (NULL);
	str[len + sign] = '\0';
	num = n;
	if (num < 0)
		num = -num;
	while (len > 0)
	{
		str[len + sign - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
