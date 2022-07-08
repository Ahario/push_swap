/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:28 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 16:06:29 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps	*ps_a)
{
	int	temp;

	temp = 0;
	temp = ps_a->stack[0];
	ps_a->stack[0] = ps_a->stack[1];
	ps_a->stack[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_ps *ps_b)
{
	int	temp;

	temp = 0;
	temp = ps_b->stack[0];
	ps_b->stack[0] = ps_b->stack[1];
	ps_b->stack[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_ps *ps_a, t_ps *ps_b)
{
	int	temp_a;
	int	temp_b;

	temp_a = 0;
	temp_a = ps_a->stack[0];
	ps_a->stack[0] = ps_a->stack[1];
	ps_a->stack[1] = temp_a;
	temp_b = 0;
	temp_b = ps_b->stack[0];
	ps_b->stack[0] = ps_b->stack[1];
	ps_b->stack[1] = temp_b;
	write(1, "ss\n", 3);
}

void	pa(t_ps *ps_a, t_ps *ps_b)
{
	int	b_top;

	b_top = ps_b->stack[0];
	ps_a->array_total++;
	ft_strdup_push_backward(ps_a);
	ps_a->stack[0] = b_top;
	ft_strdup_push_forward(ps_b);
	ps_b->array_total--;
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	pb(t_ps *ps_a, t_ps *ps_b)
{
	int	a_top;

	a_top = ps_a->stack[0];
	ps_b->array_total++;
	ft_strdup_push_backward(ps_b);
	ps_b->stack[0] = a_top;
	ft_strdup_push_forward(ps_a);
	ps_a->array_total--;
	write(1, "pb", 2);
	write(1, "\n", 1);
}
