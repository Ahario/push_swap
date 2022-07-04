#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
    int *stack;
    int *temp_stack;
    int *complete_stack;
    int array_total;
    int total;
    int half_total;
    int half_start;
    int half_end;
}t_push_swap;

//ft_split
int	check(char const str, char *charset);
int	findsecond(char const *str, char *charset);
int	findfirst(char const *str, char *charset);
char	**malloc_free(char **all);
char	**ft_split(char const *s, char *c);
//utils
void	*ft_strdup_push_forward(t_push_swap *ps);
void	*ft_strdup_push_backward(t_push_swap *ps);
char	**parsing_integers(char **argv);
int free_my_temp(char **temp);
int get_total_argc(char **argv);
//utils2
int	ft_strlen_double(char **s);
int	ft_strchr(char *s, char *c);
long long	ft_atoi(const char *str);
int check_place(char *before_atoi);
void check_parsing(char **before_atoi);
//commands
void sa(t_push_swap *ps_a);
void sb(t_push_swap *ps_b);
void ss(t_push_swap *ps_a, t_push_swap *ps_b);
void pa(t_push_swap *ps_a, t_push_swap *ps_b);
void pb(t_push_swap *ps_a, t_push_swap *ps_b);
//commands2
void ra(t_push_swap *ps_a);
void rb(t_push_swap *ps_b);
void rr(t_push_swap *ps_a, t_push_swap *ps_b);
void rra(t_push_swap *ps_a);
void rrb(t_push_swap *ps_b);
//commands3
void rrr(t_push_swap *ps_a, t_push_swap *ps_b);
//utils3
char	*ft_strdup(const char *s1);
void push_swap_error();
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	*ft_strdup_int(int *s1, int total);
void sort_my_array(int *array, int total);
//no_write
void sa_no_write(t_push_swap *ps);
void pa_no_write(t_push_swap *ps_a, t_push_swap *ps_b);
void ra_no_write(t_push_swap *ps_a);
void rra_no_write(t_push_swap *ps_a);
//utils4
void less_than_three(int *array, t_push_swap *ps_a);
int sort_complete(int *my_array, t_push_swap *ps);
void init_my_struct(t_push_swap *ps_a, t_push_swap *ps_b, int *array, int real_argc);
void with_sa(int *my_array, t_push_swap *ps_a);
void less_than_five(int *my_array, t_push_swap *ps_a, t_push_swap *ps_b);
void copy_array_to_temp(t_push_swap *ps);
void find_minimum_ra_rra(int target, t_push_swap *ps);
void ra_repeat(int target, t_push_swap *ps);
void rra_repeat(int target, t_push_swap *ps);
int sort_complete_temp(int *my_array, t_push_swap *ps);

void	*ft_memmove(int *half, t_push_swap *ps_a);
void push_from_stack_b_less_than_20(int *half, t_push_swap *ps_a, t_push_swap *ps_b);

int find_minimum_ra_rra_100(int target, t_push_swap *ps);
int find_minimum_ra_rra_500(int target, t_push_swap *ps);
void single_chunk_rra(int target, t_push_swap *ps_a, t_push_swap *ps_b);
void single_chunk_ra(int target, t_push_swap *ps_a, t_push_swap *ps_b);
void push_from_stack_b(int *half, t_push_swap *ps_a, t_push_swap *ps_b);
void push_swap_single_chunk(int *my_array, t_push_swap *ps_a, t_push_swap *ps_b);
int find_minimum_ra_rra_600(int target, t_push_swap *ps);

void max_num_pa(int k, t_push_swap *ps_a, t_push_swap *ps_b);
void min_num_pa(int i, t_push_swap *ps_a, t_push_swap *ps_b);

#endif