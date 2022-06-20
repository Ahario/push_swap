#include "push_swap.h"

int	ft_strchr(char *s, char *c)
{
	char	target;
	int		i;

	i = 0;
	target = c[0];
	while (s[i] != '\0')
	{
		if (s[i] == target)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int				i;
	int				neg;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * neg);
}

int check_parsing(char **before_atoi)
{
    long long check;
    int i;

    i = 0;
    check = 0;

}