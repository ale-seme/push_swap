/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algorithm.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 22:31:07 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/13 23:25:18 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void divide_in_two(t_list **stack_a, t_list **stack_b, t_push *push, int origin_len)
{
    int	i;
	
	i = 0;
	while(i < origin_len)
	{
		if ((*stack_a)->index <= push->mid)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index < (push->mid / 2))
				rr(stack_a, stack_b);
			else
				ra(stack_a, stack_b);
		}
		i++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}
void	sorting_emptying_b(t_list **stack_a, t_list **stack_b, t_push *push)
{
	int	len_b;
	int	i;

	i = 0;
	len_b = ft_lstsize(*stack_b);
	while(i < len_b && ft_lstsize(*stack_b))
	{
		if((*stack_b)->index == push->next)
		{
			find_next(stack_a, stack_b, push);
		}
		else if ((*stack_b)->index >= push->mid)
		{
			(*stack_b)->flag = push->flag;
			pa(stack_a, stack_b);
		}
		else if ((ft_lstsize(*stack_b) > 1 && (*stack_b)->index < push->mid))
		{
			rb(stack_b);
		}
		i++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
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
		if(ft_lstsize(stack_b) == 0)
		{
			sorting_a(stack_a, stack_b, &push);
		}
		else
		{
			sorting_emptying_b(stack_a, stack_b, &push);
		}
	}
	
}