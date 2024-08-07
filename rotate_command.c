#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last_node;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}

