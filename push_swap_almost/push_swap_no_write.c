#include "push_swap.h"

void sa_no_write(t_push_swap *ps)
{
    int temp;

    temp = 0;
    ps->temp_stack[0] = temp;
    ps->temp_stack[0] = ps->temp_stack[1];
    ps->temp_stack[1] = temp;
}

void pa_no_write(t_push_swap *ps_a, t_push_swap *ps_b)
{
    int b_top;

    b_top = ps_b->stack[0];
    ft_strdup_push_backward(ps_a);
    ps_a->stack[0] = b_top;
    ps_a->total++;
    ft_strdup_push_forward(ps_b);
    ps_b->total--;
}

void ra_no_write(t_push_swap *ps_a)
{
    int	i;
    int a_top;
    
    a_top = 0;
    i = 0;
    a_top = ps_a->temp_stack[0];
	while(i != ps_a->array_total - 1)
	{
		ps_a->temp_stack[i] = ps_a->temp_stack[i + 1];
		i++;
	}
    ps_a->temp_stack[ps_a->array_total-1] = a_top;
}

void rra_no_write(t_push_swap *ps_a)
{
    int	i;
    int a_bot;

    a_bot = 0;
    a_bot = ps_a->temp_stack[ps_a->array_total-1];
	i = ps_a->array_total-1;
	while(i != 0)
	{
		ps_a->temp_stack[i] = ps_a->temp_stack[i - 1];
		i--;
	}
    ps_a->temp_stack[0] = a_bot;
}