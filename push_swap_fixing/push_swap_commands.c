#include "push_swap.h"

void sa(int *array1, int *array2)
{
    int temp;

    temp = 0;
    array1[0] = temp;
    array1[0] = array1[1];
    array1[1] = temp;
    write(1, "sa", 2);
    write(1, "\n", 1);
}

void sb(int *array1, int *array2)
{
   int temp;

    temp = 0;
    array2[0] = temp;
    array2[0] = array2[1];
    array2[1] = temp;
    write(1, "sb", 2);
    write(1, "\n", 1);
}

void ss(int *array1, int *array2)
{
    sa(array1, array2);
    sb(array1, array2);
    write(1, "ss", 2);
    write(1, "\n", 1);
}

void pa(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int b_top;

    b_top = array2[0];
    ft_strdup_push_backward(array1, ps_a);
    array1[0] = b_top;
    ps_a->total++;
    ft_strdup_push_forward(array2, ps_b);
    ps_b->total--;
    write(1, "pa", 2);
    write(1, "\n", 1);
}

void pb(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int a_top;

    a_top = array1[0];
    ft_strdup_push_backward(array2, ps_b);
    array2[0] = a_top;
    ps_b->total++;
    ft_strdup_push_forward(array1, ps_a);
    ps_a->total--;
    write(1, "pb", 2);
    write(1, "\n", 1);
}