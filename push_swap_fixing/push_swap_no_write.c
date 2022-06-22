#include "push_swap.h"

void sa_no_write(int *array1)
{
    int temp;

    temp = 0;
    array1[0] = temp;
    array1[0] = array1[1];
    array1[1] = temp;
}

void pa_no_write(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int b_top;

    b_top = array2[0];
    ft_strdup_push_backward(array1, ps_a);
    array1[0] = b_top;
    ps_a->total++;
    ft_strdup_push_forward(array2, ps_b);
    ps_b->total--;
}

void ra_no_write(int *array1, t_push_swap *ps_a)
{
    int a_top;
    
    a_top = 0;
    a_top = array1[0];

    ft_strdup_push_forward(array1, ps_a);
    array1[ps_a->total - 1] = a_top;
}

void rra_no_write(t_push_swap *ps_a)
{
    int a_bot;

    a_bot = 0;
    a_bot = ps_a->array[ps_a->total - 1];

    ft_strdup_push_backward(array1, ps_a);
    array1[0] = a_bot;
    write(1, "rra", 2);
    write(1, "\n", 1);
}