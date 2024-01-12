/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algorithm.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 22:31:07 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/12 18:10:28 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void divide_in_two(t_list **stack_a, t_list **stack_b, t_push *push, int origin_len)
{
    
}




void sorting_algorithm(t_list **stack_a, t_list **stack_b, int origin_len)
{
    t_push	push;

	push.next = return_node_with_min_value(stack_a)->index;
	push.max = return_node_with_max_value(stack_a)->index;
	push.mid = push.max / 2 + push.next;
	divide_in_two(stack_a, stack_b, &push, origin_len);
	while(!is_sorted(stack_a, origin_len))
	{
		if(!ft_lstsize(stack_b))
		{
			sorting_1(stack_a, stack_b, &push);
		}
		else
		{
			sorting_2(stack_a, stack_b, &push);
		}
	}
	
}