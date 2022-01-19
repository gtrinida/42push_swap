#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

 int	ft_nonspace(char c)
 {
 	return (c == '\t' || c == '\v' || c == '\f'
 		|| c == '\r' || c == '\n' || c == ' ');
 }

 int	ft_checklong(int result, int term, int sign)
 {
 	long long int	res;

 	res = result;
 	res = result * 10 + term;
 	if (sign == 1)
 	{
 		if (res > 2147483647)
 			return (-1);
 	}
 	if (sign == -1)
 	{
 		if (res < -2147483648)
 			return (0);
 	}
 	return (1);
 }

 int	ft_atoi(char *str)
 {
 	int	i;
 	int	sign;
 	int	result;

 	i = 0;
 	sign = 1;
 	result = 0;
 	while (str[i] && ft_nonspace(str[i]))
 		i++;
 	if (str[i] == '-')
 	{
 		sign = -1;
 		i++;
 	}
 	else if (str[i] == '+')
 		i++;
 	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
 	{
 		if (ft_checklong(result, (str[i] - '0'), sign) != 1)
 			return (ft_checklong(result, (str[i] - '0'), sign));
 		result = result * 10 + (str[i] - '0');
 		i++;
 	}
 	return (result * sign);
 }

void	free_stack(t_stack **A)
{
	t_stack *tmp;

	while ((*A)->next)
	{	
		tmp = *A;
		A = (*A)->next;
		free (tmp);
	}
}

void	print(t_stack *A)
{
	while (A->next)
	{
		printf("%d ", A->val);
		A = A->next;
	}
	printf("%d \n", A->val);
}

void	add_new_node_reverse(t_stack **head, int val)
{
	t_stack *new_node;
	new_node = create_node(val);
	new_node->next = *head;
	*head = new_node;
}

int main(int argc, char **arvg)
{
	t_stack *A = NULL;

	int tmp;
	int i;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(arvg[i]);
		add_new_node(&A, tmp);
		i++;
	}
    ft_rrb(&A);
	print(A);
	free_stack(&A);
	return (0);
}
