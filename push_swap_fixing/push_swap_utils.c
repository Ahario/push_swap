#include "push_swap.h"

void	*ft_strdup_push_forward(int *array, t_push_swap *ps)
{
	int	i;

	i = 0;
	while(i != ps->total - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
}

void	*ft_strdup_push_backward(int *array, t_push_swap *ps)
{
	int	i;

	i = ps->total - 1;
	while(i != 0)
	{
		array[i] = array[i - 1];
		i--;
	}
}

char	**parsing_integers(char **argv)
{
	int	i;
	int j;
	int	k;
	char **before;
	char **temp;

	i = 1;
	j = 0;
	k = 0;
	temp = NULL;
	before = malloc(sizeof(char *) * (get_total_argc(argv) + 1));
	while(argv[i] != NULL)
	{
		if (ft_strchr(argv[i], " "))
		{
			temp = ft_split(argv[i], " ");
			while(temp[k] != NULL)
				before[j++] = temp[k++];
			k = free_my_temp(temp);
		}
		else
			before[j++] = ft_strdup(argv[i]);
		i++;
	}
	before[j] = NULL;
	return (before);
}

int free_my_temp(char **temp)
{
	free(temp);
	return (0);
}

int get_total_argc(char **argv)
{
	int total;
	int i;
	int	j;
	char **temp;

	i = 1;
	j = 0;
	total = 0;
	temp = NULL;
	while(argv[i] != NULL)
	{
		if (ft_strchr(argv[i], " "))
		{
			temp = ft_split(argv[i], " ");
			while(temp[j] != NULL)
				free(temp[j++]);
			free(temp);
			temp = NULL;
			total += j;
			j = 0;
		}
		else
			total++;
		i++;
	}
	return (total);
}