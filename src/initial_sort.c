/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ale <ale@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:54:43 by ale           #+#    #+#                 */
/*   Updated: 2024/01/28 21:36:28 by ale           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node3_sort(t_swap *tab)
{
	t_list	*last_in_stack;

	//there is a problem with the sorting of 3 numbers, you could remove and let the sorting algoritm do the job or do 
	if (is_sorted(&tab->stack_a))
		return ;
	last_in_stack = ft_lstlast(tab->stack_a);
	if (is_sorted_reversed(tab))
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	//might be related to one of these cases
	else if (tab->stack_a->content > tab->stack_a->next->content
		&& tab->stack_a->next->content < last_in_stack->content)
		ra(&tab->stack_a);
	else if (tab->stack_a->content > tab->stack_a->next->content
		&& tab->stack_a->next->content < last_in_stack->content)
		sa(&tab->stack_a);
	else if (tab->stack_a->content < tab->stack_a->next->content
		&& tab->stack_a->next->content > last_in_stack->content)
	{
		rra(&tab->stack_a);
		sa(&tab->stack_a);
	}
	else if (tab->stack_a->content > last_in_stack->content
		&& tab->stack_a->next->content > last_in_stack->content)
		rra(&tab->stack_a);
}

static void	node5_sort(t_swap *tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	while (len)
	{
		if (tab->stack_a->index == 1 || tab->stack_a->index == 0)
		{
			pb(&tab->stack_a, &tab->stack_b);
		}
		else
		{
			ra(&tab->stack_a);
		}
		len--;
	}
	node3_sort(tab);
	pa(&tab->stack_a, &tab->stack_b);
	pa(&tab->stack_a, &tab->stack_b);
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a);
	if (!is_sorted(&tab->stack_a))
		write (2, "Error with the sorting\n", 24);
}

void	choose_and_sort(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (is_sorted(&tab->stack_a))
		return ;
	if (len == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	else if (len == 3)
		node3_sort(tab);
	else if (len == 5)
		node5_sort(tab);
	else
		sort_algorithm(&tab->stack_a, &tab->stack_b, ft_lstsize(tab->stack_a));
}
