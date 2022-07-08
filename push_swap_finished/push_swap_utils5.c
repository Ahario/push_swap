/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:56 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:00 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum_ra_rra_100(int	target, t_ps *ps)
{
	int	ra_count;
	int	rra_count;

	ra_count = 0;
	rra_count = 0;
	copy_array_to_temp(ps);
	while (ps->t_stack[0] > target)
	{
		ra_no_write(ps);
		ra_count++;
	}
	free(ps->t_stack);
	copy_array_to_temp(ps);
	while (ps->t_stack[0] > target)
	{
		rra_no_write(ps);
		rra_count++;
	}
	free(ps->t_stack);
	if (ra_count <= rra_count)
		return (1);
	else
		return (2);
}

int	find_minimum_ra_rra_500(int target, t_ps *ps)
{
	int	ra_count;
	int	rra_count;

	ra_count = 0;
	rra_count = 0;
	copy_array_to_temp(ps);
	while (ps->t_stack[0] != target)
	{
		ra_no_write(ps);
		ra_count++;
	}
	free(ps->t_stack);
	copy_array_to_temp(ps);
	while (ps->t_stack[0] != target)
	{
		rra_no_write(ps);
		rra_count++;
	}
	free(ps->t_stack);
	if (ra_count <= rra_count)
		return (1);
	else
		return (2);
}

int	f_600(int target, t_ps *ps)
{
	int	ra_count;
	int	rra_count;

	ra_count = 0;
	rra_count = 0;
	copy_array_to_temp(ps);
	while (ps->t_stack[0] != target)
	{
		ra_no_write(ps);
		ra_count++;
	}
	free(ps->t_stack);
	copy_array_to_temp(ps);
	while (ps->t_stack[0] != target)
	{
		rra_no_write(ps);
		rra_count++;
	}
	free(ps->t_stack);
	if (ra_count <= rra_count)
		return (ra_count);
	else
		return (rra_count);
}

void	*ft_memmove(int *half, t_ps *ps_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 1;
	temp = 0;
	while (i != ps_a->half_total)
	{
		temp = half[j];
		half[i] = temp;
		i++;
		j++;
	}
	ps_a->half_total--;
	return (0);
}

void	sort_in_b(int *half, t_ps *ps_a, t_ps *ps_b)
{
	while (ps_b->stack[0] < ps_b->c_stack[half[1]])
	{
		if (ps_b->stack[0] == ps_b->c_stack[half[0]])
		{
			pa(ps_a, ps_b);
			if (ps_b->array_total != 0)
				rr(ps_a, ps_b);
			half[0]++;
		}
		else
			rb(ps_b);
	}
}
