#include "push_swap.h"

static void	replace_index(t_list *stack, int current_min, int i)
{
	t_list	*tp;

	tp = stack;
	while(tp)
	{
		if(tp->content == current_min && tp->index == -1)
			break ;
		tp = tp->next;
	}
	tp->index = i;
}

static long int	min_nbr(t_list *stack)
{
	t_list		*tp;
	long int 	min;

	min = LONG_MAX;
	tp = stack;

	while(tp)
	{
		if(tp->index == -1 && tp->content < min)
			min = tp->content;
		tp = tp->next;
	}
	return (min);
}

void	add_index(t_list *stack)
{
	int	min;
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(stack);
	while (i < len)
	{
		min = min_nbr(stack);
		replace_index(stack, min, i);
		i++;
	}
}