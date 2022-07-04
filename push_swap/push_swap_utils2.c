#include "push_swap.h"

int	ft_strlen_double(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

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

long long	ft_atoi(const char *str)
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

int check_place(char *before_atoi)
{
	int	i;
	int	flag;
	int	neg;

	neg = 0;
	i = 0;
	flag = 0;
	while(before_atoi[i] != '\0')
	{
		if (before_atoi[i] >= '0' && before_atoi[i] <= '9')
			i++;
		else
			if ((before_atoi[i] == '+' || before_atoi[i] == '-') && i == 0)
				neg = 1;
			else
			{
				flag = 1;
				break;
			}
			i++;
	}
	if (i - neg <= 10 && flag == 0 && i - neg >= 1)
		return (1);
	return (0);
}

void check_parsing(char **before_atoi)
{
    long long check;
    int i;

    i = 0;
    check = 0;
	while(before_atoi[i] != NULL)
	{
		if(!(check_place(before_atoi[i])))
			push_swap_error();
		check = ft_atoi(before_atoi[i]);
		if (check > 2147483647 || check < -2147483648)
			push_swap_error();
		i++;
	}
}