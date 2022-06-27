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

void push_from_stack_b(int *half, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int i;
    int j;

    half[ps_a->half_total] = half[1] / 2;
    j = half[ps_a->half_total];
    i = half[0];
    ps_a->half_total++;
    while (i < half[1])
    {
        while(ps_b->stack[0] < ps_b->complete_stack[j])
            ra(ps_b);
        pa(ps_a, ps_b);
        i++;
    }
    sort_my_array(half, ps_a->half_total);
    if (half[1] == 1)
    {
        pa(ps_a, ps_b);
        return;
    }
    if (ps_b->array_total != 0)
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
    for(int i = 0; i < ps_a->array_total; i++)
    {
        printf("%d\n", ps_a->stack[i]);
    }
    exit(1);
    push_from_stack_b(half, ps_a, ps_b);
}