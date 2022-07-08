/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:19 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:21 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ra(int *h_a, int target, t_ps *ps_a, t_ps *ps_b)
{
	int		i;
	int		half;

	half = (ps_a->total / 2) + 1;
	i = 0;
	while (i < half)
	{
		while (ps_a->stack[0] >= target)
		{
			if (ps_b->stack[0] < ps_a->c_stack[h_a[1] / 2]
				&& ps_b->array_total > 1)
				rr(ps_a, ps_b);
			else
				ra(ps_a);
		}
		pb(ps_a, ps_b);
		i++;
	}
}

int	check_bigger(int *half, t_ps *ps_b)
{
	int	i;
	int	j;

	i = 0;
	j = ps_b->array_total ;
	if (j < 0)
		return (1);
	while (i != j)
	{
		if (ps_b->stack[i] >= ps_b->c_stack[half[1]])
			return (0);
		i++;
	}
	return (1);
}

void	push_from_stack_a(int *half, t_ps *ps_a, t_ps *ps_b)
{
	if (half[0] == half[1])
		ft_memmove(half, ps_a);
	while (ps_a->stack[0] < ps_a->c_stack[half[1]])
		ra(ps_a);
	ft_memmove(half, ps_a);
	if (ps_a->c_stack[half[0]] == ps_a->c_stack[ps_a->total - 1])
		ra(ps_a);
	half[ps_a->half_total++] = ((half[1] + half[0] + 1) / 2);
	sort_my_array(half, ps_a->half_total);
	if (sort_complete(ps_a->c_stack, ps_a) == 0)
	{
		sort_in_a(half, ps_a, ps_b);
		if (ps_b->array_total <= 40)
			push_from_stack_b_less_than_20(half, ps_a, ps_b);
		else
			push_from_stack_b(half, ps_a, ps_b);
	}
	if (sort_complete(ps_a->c_stack, ps_a) == 0)
		push_from_stack_a(half, ps_a, ps_b);
}

void	max_num_pa(int k, t_ps *ps_a, t_ps *ps_b)
{
	while (ps_b->stack[0] < ps_b->c_stack[k])
	{
		if (find_minimum_ra_rra_500(ps_b->c_stack[k], ps_b) == 1)
			rb(ps_b);
		else
			rrb(ps_b);
	}
	if (ps_b->stack[0] == ps_b->c_stack[k])
		pa(ps_a, ps_b);
}

void	min_num_pa(int i, t_ps *ps_a, t_ps *ps_b)
{
	int	j;
	int	flag;

	j = i;
	flag = 0;
	while (ps_b->stack[0] > ps_b->c_stack[i])
	{
		if (ps_b->stack[0] == ps_b->c_stack[j + 1] && flag == 0)
		{
			pa(ps_a, ps_b);
			flag = 1;
		}
		else if (find_minimum_ra_rra_500(ps_b->c_stack[i], ps_b) == 1)
			rb(ps_b);
		else if (find_minimum_ra_rra_500(ps_b->c_stack[i], ps_b) != 1)
			rrb(ps_b);
	}
	if (ps_b->stack[0] == ps_b->c_stack[i])
	{
		pa(ps_a, ps_b);
		ra(ps_a);
		if (flag == 1)
			ra(ps_a);
	}
}
