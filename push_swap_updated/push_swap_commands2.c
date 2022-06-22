#include "push_swap.h"

void ra(int *array1, int *array2, t_push_swap *ps_a)
{
    int a_top;
    int *temp;

    temp = NULL;
    a_top = array1[0];
    temp = strdup_push_forward(array1, ps_a);
    free(array1);
    array1 = temp;
    array1[ps_a->array_total - 1] = a_top;
    write(1, "ra", 2);
    write(1, "\n", 1);
}

void rb(int *array1, int *array2, t_push_swap *ps_b)
{
    int b_top;
    int *temp;

    temp = NULL;
    b_top = array2[0];
    temp = strdup_push_forward(array2, ps_b);
    free(array2);
    array2 = temp;
    array2[ps_b->array_total  - 1] = b_top;
    write(1, "rb", 2);
    write(1, "\n", 1);
}

void rr(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b)
{
    ra(array1, array2, ps_a);
    rb(array1, array2, ps_b);
    write(1, "rr", 2);
    write(1, "\n", 1);
}

void rra(int *array1, int *array2, t_push_swap *ps_a)
{
    int a_bot;
    int *temp;

    temp = NULL;
    a_bot = array1[ps_a->total - 1];
    temp = strdup_push_backward(array1, ps_a, 1);
    free(array1);
    array1 = temp;
    array1[0] = a_bot;
    write(1, "rra", 2);
    write(1, "\n", 1);
}

void rrb(int *array1, int *array2, t_push_swap *ps_b)
{
    int b_bot;
    int *temp;

    temp = NULL;
    b_bot = array2[ps_b->total - 1];
    temp = strdup_push_backward(array2, ps_b, 1);
    free(array2);
    array2 = temp;
    array2[0] = b_bot;
    write(1, "rrb", 2);
    write(1, "\n", 1);
}