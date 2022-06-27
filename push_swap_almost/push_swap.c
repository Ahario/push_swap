#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	t_push_swap *ps_a;
	t_push_swap *ps_b;
	char **before_atoi;
	int *my_array;

	ps_a = malloc(sizeof(t_push_swap) * 1);
	ps_b = malloc(sizeof(t_push_swap) * 1);
	i = 0;
	if (argc < 1)
		push_swap_error();
	before_atoi = parsing_integers(argv);
	check_parsing(before_atoi);
	my_array = malloc(sizeof(int) * (ft_strlen_double(before_atoi)));
	while(before_atoi[i] != NULL)
	{
		my_array[i] = ft_atoi(before_atoi[i]);
		i++;
	}
	init_my_struct(ps_a, ps_b, my_array, i);
//	sort_my_array(my_array, ft_strlen_double(before_atoi));
	if (ps_a->total <= 3)
		less_than_three(my_array, ps_a);
	if (ps_a->total <= 5)
		less_than_five(my_array, ps_a, ps_b);
	else
		push_swap_single_chunk(my_array, ps_a, ps_b);
}
