/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 12:39:03 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/16 15:25:19 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../libft/libft.h"

typedef struct s_push
{
	int next;
	int max;
	int mid;
	int flag;
}   t_push; 

typedef struct s_swap
{
	t_list  *stack_a;
	t_list  *stack_b;
	int     asize;
	int     bsize;
}           t_swap;

void	add_index(t_list *stack);

t_list	*return_node_with_max_value(t_list **stack);
t_list	*return_node_with_min_value(t_list **stack);
void	divide_in_two(t_list **stack_a, t_list **stack_b, t_push *push, int origin_len);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rra(t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list	**stack_b);
void	ss(t_list **stack_a, t_list **stack_b);









#endif