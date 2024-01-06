#include "push_swap.h"

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

	}
}

