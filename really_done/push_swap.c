/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:43:53 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/08 12:02:38 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_ps		*ps_a;
	t_ps		*ps_b;
	char		**before_atoi;
	int			*my_array;

	ps_a = malloc(sizeof(t_ps) * 1);
	ps_b = malloc(sizeof(t_ps) * 1);
	i = 0;
	if (check_argc(argc, argv, ps_a, ps_b) == 0)
		push_swap_e_f_b(ps_a, ps_b);
	before_atoi = parsing_integers(argv);
	check_parsing(before_atoi);
	my_array = malloc(sizeof(int) * (ft_strlen_double(before_atoi)));
	if (!my_array)
		push_swap_e_f(before_atoi, my_array, ps_a, ps_b);
	while (before_atoi[i] != NULL)
	{
		my_array[i] = ft_atoi(before_atoi[i]);
		i++;
	}
	init_my_struct(ps_a, ps_b, my_array, i);
	if (sort_complete(my_array, ps_a) == 0)
		init_push_swap(my_array, ps_a, ps_b);
	free_my_ps(before_atoi, my_array, ps_a, ps_b);
}
