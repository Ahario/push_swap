#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
    int *stack;
    int array_total;
    int total;
}t_push_swap;

//ft_split
int	check(char const str, char *charset);
int	findsecond(char const *str, char *charset);
int	findfirst(char const *str, char *charset);
char	**malloc_free(char **all);
char	**ft_split(char const *s, char *c);
//utils
void	*ft_strdup_push_forward(int *array, t_push_swap *ps);
void	*ft_strdup_push_backward(int *array, t_push_swap *ps);
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
//void sa(int *array1, int *array2);
//void sb(int *array1, int *array2);
//void ss(int *array1, int *array2);
//void pa(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
//void pb(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
//commands2
//void ra(int *array1, int *array2, t_push_swap *ps_a);
//void rb(int *array1, int *array2, t_push_swap *ps_b);
//void rr(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
//void rra(int *array1, int *array2, t_push_swap *ps_a);
//void rrb(int *array1, int *array2, t_push_swap *ps_b);
//commands3
//void rrr(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
//utils3
char	*ft_strdup(const char *s1);
void push_swap_error();
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	*ft_strdup_int(int *s1, int total);
void sort_my_array(int *array, int total);

void sa_no_write(int *array1);
void pa_no_write(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
void ra_no_write(int *array1, t_push_swap *ps_a);
void rra_no_write(int *array1, t_push_swap *ps_a);

#endif