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

void	single_chunk_ra(int *half_array, int target, t_push_swap *ps_a, t_push_swap *ps_b)
{
	int		i;
	int		half;

	half = (ps_a->total / 2) + 1;
	i = 0;
	while(i < half)
	{
		while(ps_a->stack[0] >= target)
		{
			if (ps_b->stack[0] < ps_a->complete_stack[half_array[1] / 2] && ps_b->array_total > 1)
				rr(ps_a, ps_b);
			else
				ra(ps_a);
		}
		pb(ps_a, ps_b);
		i++;
	}
}

int check_bigger(int *half, t_push_swap *ps_b)
{
    int i;
    int j;

    i = 0;
    j = ps_b->array_total ;
    if (j < 0)
        return (1);
    while(i != j)
    {
        if(ps_b->stack[i] >= ps_b->complete_stack[half[1]])
            return(0);
        i++;
    }
    return (1);
}

void push_from_stack_a(int *half, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int j;

    j = 1;
    if (half[0] == half[1])
        ft_memmove(half, ps_a);
    while(ps_a->stack[0] < ps_a->complete_stack[half[1]])
        ra(ps_a);
    ft_memmove(half, ps_a);
    if(ps_a->complete_stack[half[0]] == ps_a->complete_stack[ps_a->total - 1])
        ra(ps_a);
    half[ps_a->half_total++] = ((half[1] + half[0] + 1) / 2);
    sort_my_array(half, ps_a->half_total);
    if (sort_complete(ps_a->complete_stack, ps_a) == 0)
    {
        while(ps_a->complete_stack[half[2]] >= ps_a->stack[0] && ps_a->complete_stack[half[0]] <= ps_a->stack[0])
        {
                if(ps_a->stack[0] >= ps_a->complete_stack[half[1]])
                {
                    if (ps_b->stack[0] < ps_a->complete_stack[half[1]] && ps_b->array_total > 1)
                        rr(ps_a, ps_b);
                    else
                        ra(ps_a);
                    j++;
                }
                else
                    pb(ps_a, ps_b);
        }
        while(--j != 0)
            rra(ps_a);
        if(ps_b->array_total <= 40)
            push_from_stack_b_less_than_20(half, ps_a, ps_b);
        else
            push_from_stack_b(half, ps_a, ps_b);
    }
    if (sort_complete(ps_a->complete_stack, ps_a) == 0)
        push_from_stack_a(half, ps_a, ps_b);
}

void max_num_pa(int k, t_push_swap *ps_a, t_push_swap *ps_b)
{
    while(ps_b->stack[0] < ps_b->complete_stack[k])
    {
        if(find_minimum_ra_rra_500(ps_b->complete_stack[k], ps_b) == 1)
            rb(ps_b);
        else
            rrb(ps_b);     
    }
    if (ps_b->stack[0] == ps_b->complete_stack[k])
        pa(ps_a, ps_b);
}

void min_num_pa(int i, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int j;
    int flag;

    j = i;
    flag = 0;
    while(ps_b->stack[0] > ps_b->complete_stack[i])
    {
        if(ps_b->stack[0] == ps_b->complete_stack[j + 1] && flag == 0)
        {
            pa(ps_a, ps_b);
            flag = 1;
        }
        else if(find_minimum_ra_rra_500(ps_b->complete_stack[i], ps_b) == 1)
            rb(ps_b);
        else if (find_minimum_ra_rra_500(ps_b->complete_stack[i], ps_b) != 1)
            rrb(ps_b);
    }
    if (ps_b->stack[0] == ps_b->complete_stack[i])
    {
        pa(ps_a, ps_b);
        ra(ps_a);
        if (flag == 1)
            ra(ps_a);
    }
}

void push_from_stack_b_less_than_20(int *half, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int i;
    int k;

    i = half[0];
    k = half[1] - 1;
    while(k > i)
    {
        if (find_minimum_ra_rra_600(ps_b->complete_stack[k], ps_b) <= find_minimum_ra_rra_600(ps_b->complete_stack[i], ps_b))
        {
            max_num_pa(k, ps_a, ps_b);
            k--;
        }
        else
        {
            min_num_pa(i, ps_a, ps_b);
            i++;
            if (ps_a->complete_stack[i] == ps_a->stack[ps_a->array_total - 1])
                i++;
        }
    }
    if (ps_b->array_total == 1)
        pa(ps_a, ps_b);
    return;
}

void push_from_stack_b(int *half, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int i;
    int j;

    half[ps_a->half_total] = ((half[0] + half[1] + 1) / 2);
    ps_a->half_total++;
    sort_my_array(half, ps_a->half_total);
    i = half[0];
    j = half[1];
    while(check_bigger(half, ps_b) == 0 || (i == half[0] && j == half[0]))
    {
        while(ps_b->stack[0] < ps_b->complete_stack[j])
        {
            if (ps_b->stack[0] == ps_b->complete_stack[half[0]])
            {
                pa(ps_a, ps_b);
                if (ps_b->array_total != 0)
                    rr(ps_a, ps_b);
                half[0]++;
            }
            else
                rb(ps_b);
        }
        if (ps_b->array_total == 0)
            return;
        if (ps_b->stack[0] >= ps_b->complete_stack[j])
        {
            pa(ps_a, ps_b);
        }
    }
    if (ps_b->array_total == 1)
    {
        pa(ps_a, ps_b);
        return;
    }
    if (ps_b->array_total != 1)
        push_from_stack_b(half, ps_a, ps_b);
}

void push_swap_single_chunk(int *my_array, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int *half;
    int half_value;

    half = malloc(sizeof(int) * ps_a->total);
    half_value = my_array[(ps_a->total / 2) + 1];
    half[0] = 0;
    half[1] = (ps_a->total / 2) + 1;
    half[2] = ps_a->total - 1;
    ps_a->half_start = 0;
    ps_a->half_end = 2;
    ps_a->half_total = 3;
    ps_b->half_total = 3;
    single_chunk_ra(half, half_value, ps_a, ps_b);
    if (ps_b->array_total <= 100)
        push_from_stack_b_less_than_20(half, ps_a, ps_b);
    else
        push_from_stack_b(half, ps_a, ps_b);
    push_from_stack_a(half, ps_a, ps_b);
    free(half);
}
