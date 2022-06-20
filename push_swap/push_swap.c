#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	t_push_swap *ps_a;
	t_push_swap *ps_b;
	int **before_atoi;
	int *my_array;

	ps_a = malloc(sizeof(t_push_swap) * 1);
	ps_b = malloc(sizeof(t_push_swap) * 1);
	i = 0;
	if (argc > 2)
		exit(1);
	before_atoi = parsing_integers(argc, argv);
	if (check_parsing(before_atoi))
		exit(1);
	while(before_atoi[i] != '\0')
	{

	}
}
