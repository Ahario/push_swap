/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:33:11 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/08 12:01:51 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int	*stack;
	int	*t_stack;
	int	*c_stack;
	int	array_total;
	int	total;
	int	half_total;
	int	half_start;
	int	half_end;
}t_ps;

//ft_split
int			check(char const str, char *charset);
int			findsecond(char const *str, char *charset);
int			findfirst(char const *str, char *charset);
char		**malloc_free(char **all);
char		**ft_split(char const *s, char *c);
//utils
void		*ft_strdup_push_forward(t_ps *ps);
void		*ft_strdup_push_backward(t_ps *ps);
char		**parsing_integers(char **argv);
int			free_my_temp(char **temp);
int			get_total_argc(char **argv);
//utils2
int			ft_strlen_double(char **s);
int			ft_strchr(char *s, char *c);
long long	ft_atoi(const char *str);
int			check_place(char *before_atoi);
void		check_parsing(char **before_atoi);
//commands
void		sa(t_ps *ps_a);
void		sb(t_ps *ps_b);
void		ss(t_ps *ps_a, t_ps *ps_b);
void		pa(t_ps *ps_a, t_ps *ps_b);
void		pb(t_ps *ps_a, t_ps *ps_b);
//commands2
void		ra(t_ps *ps_a);
void		rb(t_ps *ps_b);
void		rr(t_ps *ps_a, t_ps *ps_b);
void		rra(t_ps *ps_a);
void		rrb(t_ps *ps_b);
//commands3
void		rrr(t_ps *ps_a, t_ps *ps_b);
//utils3
char		*ft_strdup(const char *s1);
void		push_swap_error(void);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			*ft_strdup_int(int *s1, int total);
void		sort_my_array(int *array, int total);
//no_write
void		sa_no_write(t_ps *ps);
void		pa_no_write(t_ps *ps_a, t_ps *ps_b);
void		ra_no_write(t_ps *ps_a);
void		rra_no_write(t_ps *ps_a);
//utils4
void		less_than_three(int *array, t_ps *ps_a);
int			sort_complete(int *my_array, t_ps *ps);
void		init_my_struct(t_ps *ps_a, t_ps *ps_b,
				int *array, int real_argc);
void		with_sa(int *my_array, t_ps *ps_a);
void		less_than_five(int *my_array, t_ps *ps_a, t_ps *ps_b);
void		copy_array_to_temp(t_ps *ps);
void		find_minimum_ra_rra(int target, t_ps *ps);
void		ra_repeat(int target, t_ps *ps);
void		rra_repeat(int target, t_ps *ps);
int			sort_complete_temp(int *my_array, t_ps *ps);

void		*ft_memmove(int *half, t_ps *ps_a);
void		push_from_stack_b_less_than_20(int *half, t_ps *ps_a, t_ps *ps_b);
int			find_minimum_ra_rra_100(int target, t_ps *ps);
int			find_minimum_ra_rra_500(int target, t_ps *ps);
void		s_ra(int *h_a, int target, t_ps *ps_a, t_ps *ps_b);
void		push_from_stack_b(int *half, t_ps *ps_a, t_ps *ps_b);
void		push_swap_single_chunk(int *my_array, t_ps *ps_a, t_ps *ps_b);
int			f_600(int target, t_ps *ps);

void		max_num_pa(int k, t_ps *ps_a, t_ps *ps_b);
void		min_num_pa(int i, t_ps *ps_a, t_ps *ps_b);
void		do_rra_and_free(t_ps *ps_a);
void		do_ra_and_free(t_ps *ps_a);
int			check_bigger(int *half, t_ps *ps_b);
void		push_from_stack_a(int *half, t_ps *ps_a, t_ps *ps_b);
void		sort_in_a(int *half, t_ps *ps_a, t_ps *ps_b);
void		sort_in_b(int *half, t_ps *ps_a, t_ps *ps_b);
int			check_argc(int argc, char **argv, t_ps *ps_a, t_ps *ps_b);
void		push_swap_e_f(char **b_a, int *m_a, t_ps *ps_a, t_ps *ps_b);
void		init_push_swap(int *my_array, t_ps *ps_a, t_ps *ps_b);
void		push_swap_e_f_b(t_ps *ps_a, t_ps *ps_b);
void		free_my_ps(char **b_a, int *m_a, t_ps *ps_a, t_ps *ps_b);
void		check_blank(char **argv, t_ps *ps_a, t_ps *ps_b);
void		push_swap_e_blank(t_ps *ps_a, t_ps *ps_b);
#endif
