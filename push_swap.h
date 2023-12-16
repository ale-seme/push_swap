/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 12:39:03 by asemerar      #+#    #+#                 */
/*   Updated: 2023/12/16 17:07:32 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_list
{
	long int		content;
	int				flag;
	int				index;
	struct s_list	*next;
}	t_list;

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
