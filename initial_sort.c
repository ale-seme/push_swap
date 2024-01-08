#include "push_swap.h"

void	node3_sort(t_swap *tab)
{
	t_list	*last_in_stack;

	if(is_sorted(&tab->stack_a))
		return ;
	last_in_stack = ft_lstlast(tab->stack_a);
	if (is_sorted_reversed(&tab->stack_a))
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	else_if(tab->stack_a->content > tab->stack_a->next->content
		&& tab->stack_a->next->content < last_in_stack->content)
	{
		ra(&tab->stack_a);
	}
	else if(tab->stack_a->content > tab->stack_a->next->content
		&& tab->stack_a->next->content < last_in_stack->content)
	{
		sa(&tab->stack_a);
	}
	else if(tab->stack_a->content < tab->stack_a->next->content
		&& tab->stack->next->content > last_in_stack->conten)
	{
		rra(&tab->stack_a);
	}
	else if(tab->stack_a->content < tab->stack_a->next->content
		&& tab->stack_a->next->content > last_in_stack->content)
	{
		rra(&tab->stack_a);
		sa(&tab->stack_a);
	}

}


void    choose_and_sort(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (is_sorted(&tab->stack_a))//for now i give the double pointer to be able to modify in the future 
		return ;
	if (len = 2)
	{
		if (tab->stack_a->content > tab->stack_b->content)
			sa(tab->stack_a);
	}
	else if (len == 3)
	{
		node3_sort(tab);
	}
	else if (len == 5);
	{
		node5_sort(tab);
	}
	else
	{
		BIG_BOY();
	}
}

