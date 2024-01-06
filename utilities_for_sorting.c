#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list *tp;

	tp = *stack;
	while(tp && tp->next)
	{
		if(tp->content > tp->next->content)
			return (0);
		tp = tp->next;
	}
	return (1);
}

t_list	*return_node_with_min_value(t_list **stack)
{
	t_list *tp;
	t_list	*min_node;

	tp = *stack;
	min_node = *stack;

	while(tp)
	{
		if(tp->content < min_node->content)
			min_node = tp;
		tp = tp->next;
	}
	return (min_node);
}
t_list	*return_node_with_max_value(t_list **stack)
{
	t_list	*tp;
	t_list	*max_node;

	tp = *stack;
	max_node = *stack;

	while(tp)
	{
		if(tp->content > max_node->content)
			max_node = tp;
		tp = tp->next;
	}
	return (max_node);
}



