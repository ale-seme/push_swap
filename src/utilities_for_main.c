/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_for_main.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 20:37:22 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/19 16:03:57 by ale           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_start(int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		return (i);
	}
	else
	{
		i = 1;
		return (i);
	}
}

void	ft_continue_main(t_swap *tab)
{
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	choose_and_sort(tab);
}
