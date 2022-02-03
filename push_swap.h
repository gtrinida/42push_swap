#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
//#include "C:\Users\ilya9\OneDrive\Desktop\Coding\Actual\push_swap\libft\libft.h"

typedef struct s_stack
{
	int		val;
	void	*next;
	int		index;
	int		direction;
	int		larger;
}t_stack;

typedef	struct s_basic
{
	t_stack *a;
	t_stack *b;
	int		min;
	int		max;
}t_basik;
//Функция для тестов
void	print(t_stack *A);
//Это функции либы
char	**ft_split(const char *s, char c);
char	*ft_strrchr(const char *string, int c);
void	*ft_calloc(size_t sym, size_t onesymsize);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi_overflow(const char *str, int *overflow);
int		ft_atoi(const char *str);
//Это новые функции
void	ft_strsfree(char **strs);
void	free_stack(t_stack **A);
void	ft_initialization(t_basik *basic);
void	ft_sa(t_basik *stack);
void	ft_sb(t_basik *stack);
void	ft_ss(t_basik *stacks);
void	ft_ra(t_basik *stack);
void	ft_rb(t_basik *stack);
void	ft_rr(t_basik *stacks);
void	ft_rra(t_basik *stack);
void	ft_rrb(t_basik *stack);
void	ft_rrr(t_basik *stacks);
void	ft_pb(t_basik *stacks);
void	ft_pa(t_basik *stacks);
void	add_new_node(t_stack **head, int val);
void	add_new_node_reverse(t_stack **head, int val);
void	down_stack(t_stack **stack);
void	swap_hg(t_stack **stack);
t_stack	*create_node(int val);
void	up_stack(t_stack **stack);
int 	ft_verification(char **argv, t_basik *stacks);
int 	ft_verification_second(char **argv, int *i, int j, t_basik *stacks);
int	ft_verification_third(char **av);
int 	check_long(char **av);
int 	check_zero(const char *str);
int 	check_int_utils(char **av, int *i, int j);
int 	check_int(char **av);
void	ft_analysis(t_basik *stack);
int ft_check_values(t_basik *stack);
int	ft_check_len(t_stack *stack);
void	ft_sort_three(t_basik *stack);
void	ft_sort_four_five(t_basik *stack);
int ft_is_sorted(t_basik *stack);
void	ft_sort_large(t_basik *stack, int len);
#endif