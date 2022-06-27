#include "push_swap.h"

int find_minimum_ra_rra_100(int target, t_push_swap *ps)
{
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    copy_array_to_temp(ps);
    while(ps->temp_stack[0] != target)
    {
        ra_no_write(ps);
        ra_count++;
    }
    copy_array_to_temp(ps);
    while(ps->temp_stack[0] != target)
    {
        rra_no_write(ps);
        rra_count++;
    }
    if(ra_count <= rra_count)
        return (1);
    else
        return (2);
}