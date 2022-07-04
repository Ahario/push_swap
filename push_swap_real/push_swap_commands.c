#include "push_swap.h"

void sa(t_push_swap *ps_a)
{
    int temp;

    temp = 0;
    temp = ps_a->stack[0];
    ps_a->stack[0] = ps_a->stack[1];
    ps_a->stack[1] = temp;
    write(1, "sa\n", 3);
}

void sb(t_push_swap *ps_b)
{
   int temp;

    temp = 0;
    temp = ps_b->stack[0];
    ps_b->stack[0] = ps_b->stack[1];
    ps_b->stack[1] = temp;
    write(1, "sb\n", 3);
}

void ss(t_push_swap *ps_a, t_push_swap *ps_b)
{
    sa(ps_a);
    sb(ps_b);
    write(1, "ss\n", 3);
}

void pa(t_push_swap *ps_a, t_push_swap *ps_b)
{
    int b_top;

    b_top = ps_b->stack[0];
    ps_a->array_total++;
    ft_strdup_push_backward(ps_a);
    ps_a->stack[0] = b_top;
    ft_strdup_push_forward(ps_b);
    ps_b->array_total--;
    write(1, "pa", 2);
    write(1, "\n", 1);
}

void pb(t_push_swap *ps_a, t_push_swap *ps_b)
{
    int a_top;

    a_top = ps_a->stack[0];
    ps_b->array_total++;
    ft_strdup_push_backward(ps_b);
    ps_b->stack[0] = a_top;
    ft_strdup_push_forward(ps_a);
    ps_a->array_total--;
    write(1, "pb", 2);
    write(1, "\n", 1);
}