#include "push_swap.h"

void ra(int *array1, t_push_swap *ps_a)
{
    int a_top;
    
    a_top = 0;
    a_top = array1[0];

    ft_strdup_push_forward(array1, ps_a);
    array1[ps_a->total - 1] = a_top;
    write(1, "ra", 2);
    write(1, "\n", 1);
}

void rb(int *array2, t_push_swap *ps_b)
{
    int b_top;

    b_top = 0;
    b_top = array2[0];

    ft_strdup_push_forward(array2, ps_b);
    array2[ps_b->array_total  - 1] = b_top;
    write(1, "rb", 2);
    write(1, "\n", 1);
}

void rr(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b)
{
    ra(array1, ps_a);
    rb(array2, ps_b);
    write(1, "rr", 2);
    write(1, "\n", 1);
}

void rra(int *array1, t_push_swap *ps_a)
{
    int a_bot;

    a_bot = 0;
    a_bot = array1[ps_a->total - 1];

    ft_strdup_push_backward(array1, ps_a);
    array1[0] = a_bot;
    write(1, "rra", 2);
    write(1, "\n", 1);
}

void rrb(int *array2, t_push_swap *ps_b)
{
    int b_bot;

    b_bot = 0;
    b_bot = array2[ps_b->total - 1];

    ft_strdup_push_backward(array2, ps_b);
    array2[0] = b_bot;
    write(1, "rrb", 2);
    write(1, "\n", 1);
}