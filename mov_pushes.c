/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mov_pushes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 23:11:36 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/06 23:11:37 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tp_a;
	t_list	*tp_b;

	if (!*stack_b)
		return ;

	tp_a = *stack_a;
	tp_b = *stack_b;
	*stack_b = tp_b->next;
	tp_b->next = tp_a;
	*stack_a = tp_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tp_a;
	t_list	*tp_b;

	if(!*stack_a)
		return ;
	tp_a = *stack_a;
	tp_b = *stack_b;
	*stack_a = tp_a->next;
	tp_a->next = tp_b;
	*stack_b = tp_a;
	write(1, "pb\n", 3);
}
