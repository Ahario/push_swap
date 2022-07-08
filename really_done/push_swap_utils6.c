/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:56 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:00 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argc(int argc, char **argv, t_ps *ps_a, t_ps *ps_b)
{
	char	**check;

	if (argc <= 1)
	{
		free(ps_a);
		free(ps_b);
		exit(1);
	}
	check_blank(argv, ps_a, ps_b);
	check = malloc(sizeof(char *) * (get_total_argc(argv) + 1));
	if (!check)
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}

void	init_push_swap(int *my_array, t_ps *ps_a, t_ps *ps_b)
{
	if (ps_a->total <= 3)
		less_than_three(my_array, ps_a);
	else if (ps_a->total <= 5)
		less_than_five(my_array, ps_a, ps_b);
	else
		push_swap_single_chunk(my_array, ps_a, ps_b);
}

void	free_my_ps(char **b_a, int *m_a, t_ps *ps_a, t_ps *ps_b)
{
	int	i;

	i = 0;
	free(ps_a->stack);
	free(ps_b->stack);
	free(ps_a->c_stack);
	free(ps_b->c_stack);
	free(ps_a);
	free(ps_b);
	free(m_a);
	while (b_a[i] != NULL)
	{
		free(b_a[i]);
		i++;
	}
	free(b_a);
}

void	push_swap_e_f(char **b_a, int *m_a, t_ps *ps_a, t_ps *ps_b)
{
	free_my_ps(b_a, m_a, ps_a, ps_b);
	push_swap_error();
}

void	push_swap_e_f_b(t_ps *ps_a, t_ps *ps_b)
{
	free(ps_a);
	free(ps_b);
	push_swap_error();
}
