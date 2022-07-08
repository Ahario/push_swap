/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:46 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:47 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_ps *ps_a, t_ps *ps_b)
{
	int	a_bot;
	int	b_bot;

	a_bot = 0;
	a_bot = ps_a->stack[ps_a->array_total - 1];
	b_bot = 0;
	b_bot = ps_b->stack[ps_b->array_total - 1];
	ft_strdup_push_backward(ps_a);
	ps_a->stack[0] = a_bot;
	ft_strdup_push_backward(ps_b);
	ps_b->stack[0] = b_bot;
	write(1, "rrr\n", 4);
}
