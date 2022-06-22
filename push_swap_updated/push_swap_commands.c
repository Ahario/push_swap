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
    int *temp;
    int *temp2;

    temp = NULL;
    temp2 = NULL;
    b_top = array2[0];
    temp = strdup_push_backward(array1, ps_a, 0);
    free(array1);
    array1 = temp;
    array1[0] = b_top;
    ps_a->array_total += 1;
    temp2 = strdup_push_forwared(array2, ps_b);
    free(array2);
    array2 = temp2;
    ps_b->array_total -= 1;
    write(1, "pa", 2);
    write(1, "\n", 1);
}

void pb(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b)
{
    int a_top;
    int *temp;
    int *temp2;

    temp = NULL;
    temp2 = NULL;
    a_top = array1[0];
    temp = strdup_push_backward(array2, ps_b, 0);
    free(array2);
    array2 = temp;
    array2[0] = a_top;
    ps_b->array_total += 1;
    temp2 = strdup_push_forwared(array1, ps_a);
    free(array1);
    array1 = temp2;
    ps_a->array_total -= 1;
    write(1, "pb", 2);
    write(1, "\n", 1);
}