#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		total;
	char	*temp;

	i = 0;
	total = 0;
	while (s1[total] != '\0')
		total++;
	temp = malloc(sizeof(char) * (total + 1));
	if (temp == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

int	*ft_strdup_int(int *s1, int total)
{
	int		i;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * (total));
	while(i != total)
	{
		temp[i] = s1[i];
		i++;
	}
	return (temp);
}

void sort_my_array(int *array, int total)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while(i != total)
	{
		j = 0;
		while(j < total - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void push_swap_error()
{
    write(1, "error", 5);
    write(1, "\n", 1);
    exit(1);
}