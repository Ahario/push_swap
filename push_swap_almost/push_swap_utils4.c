#include "push_swap.h"

int sort_complete(int *my_array, t_push_swap *ps)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(i != ps->array_total)
    {
        if(my_array[i] != ps->stack[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 1)
        return (0);
    return (1);
}

void init_my_struct(t_push_swap *ps_a, t_push_swap *ps_b, int *array, int real_argc)
{
    ps_a->stack = ft_strdup_int(array, real_argc);
    sort_my_array(array, real_argc);
    ps_a->complete_stack = ft_strdup_int(array, real_argc);
    ps_b->complete_stack = ft_strdup_int(array, real_argc);
    ps_b->stack = malloc(sizeof(int) * real_argc);
    ps_a->total = real_argc;
    ps_a->total = real_argc;
    ps_a->array_total = real_argc;
    ps_b->array_total = 0;
}

void copy_array_to_temp(t_push_swap *ps)
{
    int i;

    i = 0;

    ps->temp_stack = malloc(sizeof(int) * (ps->array_total));
    while(i != ps->array_total)
    {
        ps->temp_stack[i] = ps->stack[i];
        i++;
    }
}

int sort_complete_temp(int *my_array, t_push_swap *ps)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(i != ps->array_total)
    {
        if(my_array[i] != ps->temp_stack[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 1)
        return (0);
    return (1);
}