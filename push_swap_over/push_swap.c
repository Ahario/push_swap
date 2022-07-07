/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:43:53 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/07 15:43:54 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_push_swap	*ps_a;
	t_push_swap	*ps_b;
	char		**before_atoi;
	int			*my_array;

	ps_a = malloc(sizeof(t_push_swap) * 1);
	ps_b = malloc(sizeof(t_push_swap) * 1);
	i = 0;
	if (argc < 1)
		push_swap_error();
	before_atoi = parsing_integers(argv);
	check_parsing(before_atoi);
	my_array = malloc(sizeof(int) * (ft_strlen_double(before_atoi)));
	if (!my_array)
		return (0);
	while (before_atoi[i] != NULL)
	{
		my_array[i] = ft_atoi(before_atoi[i]);
		i++;
	}
	init_my_struct(ps_a, ps_b, my_array, i);
	if (ps_a->total <= 3)
		less_than_three(my_array, ps_a);
	else if (ps_a->total <= 5)
		less_than_five(my_array, ps_a, ps_b);
	else
		push_swap_single_chunk(my_array, ps_a, ps_b);
	free(ps_a->stack);
	free(ps_b->stack);
	free(ps_a->complete_stack);
	free(ps_b->complete_stack);
	free(ps_a);
	free(ps_b);
	free(my_array);
	i = 0;
	while(before_atoi[i] != NULL)
		free(before_atoi[i++]);
	free(before_atoi);
}
