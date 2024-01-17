/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mov_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 14:17:19 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/17 13:41:40 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first_node;

	first_node = *stack;
	*stack = first_node->next;
	first_node->next = NULL;
	ft_lstlast(*stack)->next = first_node;
}

void	ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

// static void	ft_rotate(t_list **stack)
// {
// 	t_list	*tp;
// 	t_list	*head;
// 	t_list	*soc;

// 	tp = *stack;
// 	head = *stack;
// 	while(tp && tp->next)
// 	{
// 		tp = tp->next;
// 	}
// 	soc = tp;
// 	tp->next = head->next;
// 	tp = head;
// 	head = soc;
// }