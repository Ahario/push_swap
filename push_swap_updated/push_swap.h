#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_push_swap
{
    int array_total;
    int total;
}t_push_swap;

char	*ft_strdup_push_forward(int *array, t_push_swap *ps);
char	*ft_strdup_push_backward(int *array, t_push_swap *ps, int flag);
int	**parsing_integers(int argc, char **argv);
int free_my_temp(char **temp);
int get_total_argc(int argc, char **argv);

int	ft_strlen_double(char **s);
int	ft_strchr(char *s, char *c);
long long	ft_atoi(const char *str);
int check_palce(char *before_atoi);
void check_parsing(char **before_atoi);

void sa(int *array1, int *array2);
void sb(int *array1, int *array2);
void ss(int *array1, int *array2);
void pa(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
void pb(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);

void ra(int *array1, int *array2, t_push_swap *ps_a);
void rb(int *array1, int *array2, t_push_swap *ps_b);
void rr(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);
void rra(int *array1, int *array2, t_push_swap *ps_a);
void rrb(int *array1, int *array2, t_push_swap *ps_b);

void rrr(int *array1, int *array2, t_push_swap *ps_a, t_push_swap *ps_b);

#endif