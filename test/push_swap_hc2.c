/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:46:11 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:55 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_repeat(int target, t_ps *ps)
{
	while (ps->stack[0] != target)
		ra(ps);
	if (sort_complete(ps->c_stack, ps))
		return ;
}

void	rra_repeat(int target, t_ps *ps)
{
	while (ps->stack[0] != target)
		rra(ps);
	if (sort_complete(ps->c_stack, ps))
		return ;
}
