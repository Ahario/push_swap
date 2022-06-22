#include "push_swap.h"

char	*ft_strdup_push_forward(int *array, t_push_swap *ps)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ps->total));
	if (temp == NULL)
		return (NULL);
	while (array[i + 1] != ps->array_total)
	{
		temp[i] = array[i + 1];
		i++;
	}
	return (temp);
}

char	*ft_strdup_push_backward(int *array, t_push_swap *ps, int flag)
{
	int		i;
	int		flag_total;
	char	*temp;

	i = 0;
	flag_total = ps->array_total;
	temp = malloc(sizeof(char) * (ps->total));
	if (temp == NULL)
		return (NULL);
	if (flag == 1)
		flag_total -=1;
	while (array[i] != flag_total)
	{
		temp[i + 1] = array[i];
		i++;
	}
	return (temp);
}

int	**parsing_integers(int argc, char **argv)
{
	int	i;
	int j;
	int	k;
	char **before;
	char **temp;

	i = 0;
	j = 0;
	k = 0;
	temp = NULL;
	before = malloc(sizeof(char *) * (get_total_argc(argc, argv) + 1));
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
	before[j] = '\0';
	return (before);
}

int free_my_temp(char **temp)
{
	free(temp);
	return (0);
}

int get_total_argc(int argc, char **argv)
{
	int total;
	int i;
	int	j;
	char **temp;

	i = 0;
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