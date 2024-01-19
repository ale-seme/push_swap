/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algorithm.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 22:31:07 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/19 18:14:04 by ale           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_in_2(t_list **stack_a, t_list **stack_b, t_push *push, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((*stack_a)->index <= push->mid)
			pb(stack_a, stack_b);
		else
		{
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index < (push->mid / 2))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		i++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	find_next(t_list **st_a, t_list **st_b, t_push *push)
{
	if (ft_lstsize(*st_b) > 0 && (*st_b)->index == push->next)
	{
		pa(st_a, st_b);
	}
	else if ((*st_a)->index == push->next)
	{
		(*st_a)->flag = -1;
		ra(st_a);
		push->next++;
	}
	else if (ft_lstsize(*st_b) > 1 && (*st_b)->next->index == push->next)
		sb(st_b);
	else if ((ft_lstsize(*st_b)) > 2 && ft_lstlast(*st_b)->index == push->next)
		rrb(st_b);
	else if (ft_lstsize(*st_a) > 1 && (*st_a)->next->index == push->next)
		sa(st_a);
	else if ((ft_lstsize(*st_a) > 1 && (*st_a)->next->index == push->next)
		&& ((*st_b)->next->index == push->next + 1))
		ss(st_a, st_b);
	else if (ft_lstlast(*st_a)->index == push->next)
		rra(st_a);
	else
		return ;
	find_next(st_a, st_b, push);
}

static void	sorting_emptying_b(t_list **stack_a, t_list **stack_b, t_push *push)
{
	int	len_b;
	int	i;

	i = 0;
	len_b = ft_lstsize(*stack_b);
	while (i < len_b && ft_lstsize(*stack_b))
	{
		if ((*stack_b)->index == push->next)
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

static void	sorting_a(t_list **stack_a, t_list **stack_b, t_push *push)
{
	int	flag_now;

	flag_now = (*stack_a)->flag;
	if ((*stack_a)->flag != 0)
	{
		while ((*stack_a)->flag == flag_now)
		{
			if ((*stack_a)->index != push->next)
				pb(stack_a, stack_b);
			find_next(stack_a, stack_b, push);
		}
	}
	if (ft_lstsize(*stack_b))
		push->max = (return_node_with_max_value(stack_b))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

void	sort_algorithm(t_list **stack_a, t_list **stack_b, int origin_len)
{
	t_push	push;

	push.next = return_node_with_min_value(stack_a)->index;
	push.max = return_node_with_max_value(stack_a)->index;
	push.mid = push.max / 2 + push.next;
	divide_in_2(stack_a, stack_b, &push, origin_len);
	while (!is_sorted_a(stack_a, origin_len))
	{
		if (ft_lstsize(*stack_b) == 0)
		{
			sorting_a(stack_a, stack_b, &push);
		}
		else
		{
			sorting_emptying_b(stack_a, stack_b, &push);
		}
	}
}
