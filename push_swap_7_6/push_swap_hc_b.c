#include "push_swap.h"

void less_than_three_b(int *my_array, t_push_swap *ps_a)
{
    copy_array_to_temp(ps_a);
    if (!(sort_complete(my_array, ps_a)))
    {
    	rra_no_write(ps_a);
        if (sort_complete_temp(my_array, ps_a))
        {
            rrb(ps_a);
            return ;
        }
        ra_no_write(ps_a);
        ra_no_write(ps_a);
        if (sort_complete_temp(my_array, ps_a))
        {
            rb(ps_a);
            return ;
        }
        rra_no_write(ps_a);
        sb(ps_a);
        if (!sort_complete(my_array, ps_a))
            less_than_three_b(my_array, ps_a);
        return ;
    }
}

void less_than_five_b(t_push_swap *ps_a, t_push_swap *ps_b)
{
    int *temp;
    int *array;
    int *temp2;

    temp = 0;
    array = 0;
    temp2 = 0;
    temp = ft_strdup_int(ps_b->stack, ps_b->array_total);
    sort_my_array_b(temp, ps_b->array_total);
    array = ft_strdup_int(ps_b->stack, ps_b->array_total);
    if(!(sort_complete_b(temp, array, ps_b)))
    {  
        if (ps_b->array_total > 3)
        {
            find_minimum_ra_rra_b(temp[0], ps_b);
            pa(ps_a, ps_b);
            find_minimum_ra_rra_b(temp[1], ps_b);
            pa(ps_a, ps_b);
        }
        temp2 = ft_strdup_int(&temp[2], ps_b->array_total);
        less_than_three_b(temp2, ps_b);

        while(ps_b->array_total != 0)
        {
            pa(ps_a, ps_b);
        }
    }
}

void find_minimum_ra_rra_b(int target, t_push_swap *ps)
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
        ra_repeat_b(target, ps);
    else
        rra_repeat_b(target, ps);
}

void ra_repeat_b(int target, t_push_swap *ps)
{
    while(ps->stack[0] != target)
        rb(ps);
    if (sort_complete(ps->complete_stack, ps))
        return ;
}

void rra_repeat_b(int target, t_push_swap *ps)
{
    while(ps->stack[0] != target)
        rrb(ps);
    if (sort_complete(ps->complete_stack, ps))
        return ;
}

int sort_complete_b(int *sorted, int *temp, t_push_swap *ps_b)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(i != ps_b->array_total)
    {
        if(sorted[i] != temp[i])
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

void sort_my_array_b(int *array, int total)
{
	int	i;
	int	j;
	int temp;

	i = total - 1;
	j = total - 1;
	temp = 0;
	while(i != 0)
	{
		j = total - 1;
		while(j != 0)
		{
			if (array[j] > array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
			j--;
		}
		i--;
	}
}