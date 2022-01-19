#include "push_swap.h"

void	swap_hg(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (tmp->next)
	{
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
	return ;
}

void up_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	add_new_node(stack, (*stack)->val);
	*stack = (*stack)->next;
	free(tmp);
}

void	go_down(t_stack **stack)
{
	t_stack *tmp;
	int	i;

	if(!*(stack))
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
	while(i)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

t_stack	*create_node(int val)
{
	t_stack *node;
	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->val = val;
	return(node);
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
