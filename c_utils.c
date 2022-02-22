#include "push_swap.h"
#include "libft.h"

void	swap_hg(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	if (tmp->next)
	{
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	up_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	add_new_node(stack, (*stack)->val);
	*stack = (*stack)->next;
	free(tmp);
}

t_stack	*create_node(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->val = val;
	return(node);
}

void	down_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	i = 0;
	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = *stack;
	*stack = tmp;
	while (i)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	add_new_node(t_stack **head, int val)
{
	t_stack	*tmp;

	if (!*head)
	{
		*head = create_node(val);
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_node(val);
}

void	add_new_node_reverse(t_stack **head, int val)
{
	t_stack	*new_node;

	new_node = create_node(val);
	new_node->next = *head;
	*head = new_node;
}
