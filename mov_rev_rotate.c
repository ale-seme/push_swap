/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mov_rev_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 14:17:35 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/06 17:29:05 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tp;
	t_list	*last_node;
	
	if(!((*stack) || (*stack)->next))
		return ;
	tp = *stack;
	last_node = ft_lstlast(*stack);
	while((*stack)->next->next)
	{
		*stack = (*stack)->next;
	}
	(*stack)->next = NULL;
	last_node->next = tp;
	*stack = last_node;
}

void	rra(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rra(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

