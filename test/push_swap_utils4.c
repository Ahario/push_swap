/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:45 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:05:47 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_complete(int *my_array, t_ps *ps)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i != ps->array_total)
	{
		if (my_array[i] != ps->stack[i])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

void	init_my_struct(t_ps *ps_a, t_ps *ps_b, int *array, int real_argc)
{
	int	i;

	i = 0;
	ps_a->stack = ft_strdup_int(array, real_argc);
	sort_my_array(array, real_argc);
	ps_a->c_stack = ft_strdup_int(array, real_argc);
	ps_b->c_stack = ft_strdup_int(array, real_argc);
	ps_b->stack = malloc(sizeof(int) * real_argc);
	ps_a->total = real_argc;
	ps_b->total = real_argc;
	ps_a->array_total = real_argc;
	ps_b->array_total = 0;
	while (i != real_argc - 1)
	{
		if (array[i] == array[i + 1])
			push_swap_error();
		i++;
	}
}

void	copy_array_to_temp(t_ps *ps)
{
	int	i;

	i = 0;
	ps->t_stack = malloc(sizeof(int) * (ps->array_total));
	while (i != ps->array_total)
	{
		ps->t_stack[i] = ps->stack[i];
		i++;
	}
}

int	sort_complete_temp(int *my_array, t_ps *ps)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i != ps->array_total)
	{
		if (my_array[i] != ps->t_stack[i])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}
