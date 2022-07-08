/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:56 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:00 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_blank(char **argv, t_ps *ps_a, t_ps *ps_b)
{
	int			i;
	int			j;
	char		**temp;

	i = 0;
	j = 0;
	while (argv[++i] != NULL)
	{
		j = 0;
		if (ft_strchr(argv[i], " "))
		{
			temp = ft_split(argv[i], " ");
			if (!temp[0])
			{
				free(temp[0]);
				free(temp);
				push_swap_e_blank(ps_a, ps_b);
			}
			while (temp[j] != NULL)
				free(temp[j++]);
			free(temp);
		}
	}
}

void	push_swap_e_blank(t_ps *ps_a, t_ps *ps_b)
{
	free(ps_a);
	free(ps_b);
	push_swap_error();
}
