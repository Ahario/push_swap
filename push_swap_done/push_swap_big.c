#include "push_swap.h"

void single_chunk_rra(int target, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int i;
    int half;

    half = ps_a->total / 2;
    i = 0;
    while(i < half)
    {
        while(ps_a->stack[0] > target)
        {
            rra(ps_a);
        }
        pb(ps_a, ps_b);
        i++;
    }
}

void single_chunk_ra(int target, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int i;
    int half;

    half = ps_a->total / 2;
    i = 0;
    while(i < half)
    {
        while(ps_a->stack[0] > target)
        {
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
        if(ps_b->stack[i] > ps_b->complete_stack[half[1]])
            return(0);
        i++;
    }
    return (1);
}

void push_from_stack_a(int *half, t_push_swap *ps_a, t_push_swap *ps_b)
{
    while(ps_a->stack[0] <= ps_a->complete_stack[half[0]])
        ra(ps_a);
    ps_a->half_total--;
    ft_memmove(half, ps_a);
    if(ps_a->complete_stack[half[0]] == ps_a->complete_stack[ps_a->total - 1])
    {
        ra(ps_a);
        exit(1);
    }

    if (sort_complete(ps_a->complete_stack, ps_a) == 0)
    {
        while(ps_a->complete_stack[half[1]] >= ps_a->stack[0] && ps_a->stack[0] >= ps_a->complete_stack[half[0]])
        {
            pb(ps_a, ps_b);
        }
        push_from_stack_b(half, ps_a, ps_b);
    }
    if (sort_complete(ps_a->complete_stack, ps_a) == 0)
        push_from_stack_a(half, ps_a, ps_b);
}

void push_from_stack_b(int *half, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int i;
    int j;

    half[ps_a->half_total] = (half[0] + half[1]) / 2;
    ps_a->half_total++;
    sort_my_array(half, ps_a->half_total);
    i = half[0];
    j = half[1];
    while(check_bigger(half, ps_b) == 0 || (i == half[0] && j == half[0]))
    {
       while(ps_b->stack[0] <= ps_b->complete_stack[half[1]])
        {
            rb(ps_b);
        }
        if (ps_b->stack[0] > ps_b->complete_stack[half[1]])
            pa(ps_a, ps_b);
        i++;
    }
    if (ps_b->array_total == 1)
    {
        pa(ps_a, ps_b);
        ps_a->half_total--;
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
    half_value = my_array[(ps_a->total / 2) - 1];
    half[0] = 0;
    half[1] = (ps_a->total / 2) - 1;
    half[2] = ps_a->total - 1;
    ps_a->half_start = 0;
    ps_a->half_end = 2;
    ps_a->half_total = 3;
    ps_b->half_total = 3;
    if (find_minimum_ra_rra_100(half_value, ps_a) == 1)
       single_chunk_ra(half_value, ps_a, ps_b);
    else
        single_chunk_rra(half_value, ps_a, ps_b);
    push_from_stack_b(half, ps_a, ps_b);
    push_from_stack_a(half, ps_a, ps_b);
}