/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:05 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:05:06 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_strdup_push_forward(t_push_swap *ps)
{
	int	i;

	i = 0;
	while(i != ps->array_total - 1)
	{
		ps->stack[i] = ps->stack[i + 1];
		i++;
	}
	return (0);
}

void	*ft_strdup_push_backward(t_push_swap *ps)
{
	int	i;

	i = ps->array_total-1;
	while(i != 0)
	{
		ps->stack[i] = ps->stack[i - 1];
		i--;
	}
	return (0);
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
