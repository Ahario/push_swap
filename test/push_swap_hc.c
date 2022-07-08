/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:46:11 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:55 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_than_three(int *my_array, t_ps *ps_a)
{
	copy_array_to_temp(ps_a);
	if (!(sort_complete(my_array, ps_a)))
	{
		rra_no_write(ps_a);
		if (sort_complete_temp(my_array, ps_a))
		{
			do_rra_and_free(ps_a);
			return ;
		}
		ra_no_write(ps_a);
		ra_no_write(ps_a);
		if (sort_complete_temp(my_array, ps_a))
		{
			do_ra_and_free(ps_a);
			return ;
		}
		rra_no_write(ps_a);
		sa(ps_a);
		free(ps_a->t_stack);
		if (!sort_complete(my_array, ps_a))
			less_than_three(my_array, ps_a);
		return ;
	}
	free(ps_a->t_stack);
}

void	do_rra_and_free(t_ps *ps_a)
{
	free(ps_a->t_stack);
	rra(ps_a);
}

void	do_ra_and_free(t_ps *ps_a)
{
	free(ps_a->t_stack);
	ra(ps_a);
}

void	less_than_five(int *my_array, t_ps *ps_a, t_ps *ps_b)
{
	int	*temp;

	temp = 0;
	if (!(sort_complete(my_array, ps_a)))
	{
		if (ps_a->array_total > 3)
		{
			find_minimum_ra_rra(my_array[0], ps_a);
			pb(ps_a, ps_b);
			find_minimum_ra_rra(my_array[1], ps_a);
			pb(ps_a, ps_b);
		}
		temp = ft_strdup_int(&my_array[2], ps_a->array_total);
		less_than_three(temp, ps_a);
		free(temp);
		pa(ps_a, ps_b);
		pa(ps_a, ps_b);
	}
}

void	find_minimum_ra_rra(int target, t_ps *ps)
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
		ra_repeat(target, ps);
	else
		rra_repeat(target, ps);
}
