#include "push_swap.h"

void ra(t_push_swap *ps_a)
{
    int a_top;
    
    a_top = 0;
    a_top = ps_a->stack[0];
    ft_strdup_push_forward(ps_a);
    ps_a->stack[ps_a->array_total - 1] = a_top;
    write(1, "ra\n", 3);
}

void rb(t_push_swap *ps_b)
{
    int b_top;

    b_top = 0;
    b_top = ps_b->stack[0];

    ft_strdup_push_forward(ps_b);
    ps_b->stack[ps_b->array_total  - 1] = b_top;
    write(1, "rb\n", 3);
}

void rr(t_push_swap *ps_a, t_push_swap *ps_b)
{
    int a_top;
    int b_top;

    a_top = 0;
    a_top = ps_a->stack[0];
    b_top = 0;
    b_top = ps_b->stack[0];
    ft_strdup_push_forward(ps_b);
    ps_b->stack[ps_b->array_total  - 1] = b_top;
    ft_strdup_push_forward(ps_a);
    ps_a->stack[ps_a->array_total - 1] = a_top;
    write(1, "rr\n", 3);
}

void rra(t_push_swap *ps_a)
{
    int a_bot;

    a_bot = 0;
    a_bot = ps_a->stack[ps_a->array_total - 1];

    ft_strdup_push_backward(ps_a);
    ps_a->stack[0] = a_bot;
    write(1, "rra\n", 4);
}

void rrb(t_push_swap *ps_b)
{
    int b_bot;

    b_bot = 0;
    b_bot = ps_b->stack[ps_b->array_total - 1];

    ft_strdup_push_backward(ps_b);
    ps_b->stack[0] = b_bot;
    write(1, "rrb\n", 4);
}