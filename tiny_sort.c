#include "push_swap.h"
#include <limits.h>

bool	stack_sorted(t_node *stack)
{
	if(stack == NULL)
		return (1);
	while (stack->next)
	{
		if(stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_node	*find_highest(t_node *stack)
{
	int		highest;
	t_node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_node **a)
{
	t_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
