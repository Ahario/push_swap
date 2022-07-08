/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:19 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:21 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_stack_b_less_than_20(int *half, t_ps *ps_a, t_ps *ps_b)
{
	int	i;
	int	k;

	i = half[0];
	k = half[1] - 1;
	while (k > i)
	{
		if (f_600(ps_b->c_stack[k], ps_b) <= f_600(ps_b->c_stack[i], ps_b))
		{
			max_num_pa(k, ps_a, ps_b);
			k--;
		}
		else
		{
			min_num_pa(i, ps_a, ps_b);
			i++;
			if (ps_a->c_stack[i] == ps_a->stack[ps_a->array_total - 1])
				i++;
		}
	}
	if (ps_b->array_total == 1)
		pa(ps_a, ps_b);
	return ;
}

void	push_from_stack_b(int *half, t_ps *ps_a, t_ps *ps_b)
{
	int	i;
	int	j;

	half[ps_a->half_total] = ((half[0] + half[1] + 1) / 2);
	ps_a->half_total++;
	sort_my_array(half, ps_a->half_total);
	i = half[0];
	j = half[1];
	while (check_bigger(half, ps_b) == 0 || (i == half[0] && j == half[0]))
	{
		sort_in_b(half, ps_a, ps_b);
		if (ps_b->array_total == 0)
			return ;
		if (ps_b->stack[0] >= ps_b->c_stack[j])
			pa(ps_a, ps_b);
	}
	if (ps_b->array_total == 1)
	{
		pa(ps_a, ps_b);
		return ;
	}
	if (ps_b->array_total != 1)
		push_from_stack_b(half, ps_a, ps_b);
}

void	push_swap_single_chunk(int *my_array, t_ps *ps_a, t_ps *ps_b)
{
	int	*half;
	int	half_value;

	half = malloc(sizeof(int) * ps_a->total);
	half_value = my_array[(ps_a->total / 2) + 1];
	half[0] = 0;
	half[1] = (ps_a->total / 2) + 1;
	half[2] = ps_a->total - 1;
	ps_a->half_start = 0;
	ps_a->half_end = 2;
	ps_a->half_total = 3;
	ps_b->half_total = 3;
	s_ra(half, half_value, ps_a, ps_b);
	if (ps_b->array_total <= 100)
		push_from_stack_b_less_than_20(half, ps_a, ps_b);
	else
		push_from_stack_b(half, ps_a, ps_b);
	push_from_stack_a(half, ps_a, ps_b);
	free(half);
}

void	sort_in_a(int *half, t_ps *ps_a, t_ps *ps_b)
{
	int	j;

	j = 0;
	while (ps_a->c_stack[half[2]] >= ps_a->stack[0]
		&& ps_a->c_stack[half[0]] <= ps_a->stack[0])
	{
		if (ps_a->stack[0] >= ps_a->c_stack[half[1]])
		{
			if (ps_b->stack[0] < ps_a->c_stack[half[1]]
				&& ps_b->array_total > 1)
				rr(ps_a, ps_b);
			else
				ra(ps_a);
			j++;
		}
		else
			pb(ps_a, ps_b);
	}
	while (j != 0)
	{
		rra(ps_a);
		j--;
	}
}
