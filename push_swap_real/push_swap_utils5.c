#include "push_swap.h"

int find_minimum_ra_rra_100(int target, t_push_swap *ps)
{
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    copy_array_to_temp(ps);
    free(ps->temp_stack);
    while(ps->temp_stack[0] > target)
    {
        ra_no_write(ps);
        ra_count++;
    }
    copy_array_to_temp(ps);
    free(ps->temp_stack);
    while(ps->temp_stack[0] > target)
    {
        rra_no_write(ps);
        rra_count++;
    }
    if(ra_count <= rra_count)
        return (1);
    else
        return (2);
}

int find_minimum_ra_rra_500(int target, t_push_swap *ps)
{
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    ps->temp_stack = 0;
    copy_array_to_temp(ps);
    while(ps->temp_stack[0] != target)
    {
        ra_no_write(ps);
        ra_count++;
    }
    free(ps->temp_stack);
    copy_array_to_temp(ps);
    while(ps->temp_stack[0] != target)
    {
        rra_no_write(ps);
        rra_count++;
    }
    free(ps->temp_stack);
    if(ra_count <= rra_count)
        return (1);
    else
        return (2);
}

int find_minimum_ra_rra_600(int target, t_push_swap *ps)
{
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    ps->temp_stack = 0;
    copy_array_to_temp(ps);
    while(ps->temp_stack[0] != target)
    {
        ra_no_write(ps);
        ra_count++;
    }
    free(ps->temp_stack);
    copy_array_to_temp(ps);
    while(ps->temp_stack[0] != target)
    {
        rra_no_write(ps);
        rra_count++;
    }
    free(ps->temp_stack);
    if(ra_count <= rra_count)
        return (ra_count);
    else
        return (rra_count);
}

void	*ft_memmove(int *half, t_push_swap *ps_a)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 1;
    temp = 0;
    while(i != ps_a->half_total)
    {
        if(half[j] == half[j - 1])
            j++;
        else
        {
            temp = half[j];
            half[i] = temp;
            i++;
            j++;
        }
    }
    return (0);
}
