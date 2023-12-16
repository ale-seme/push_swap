/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 16:21:03 by asemerar      #+#    #+#                 */
/*   Updated: 2023/12/16 17:33:39 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_swap* tab;
	char** arguments;

	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else 
		arguments = argv;
	tab->stack_a = ft_inizialize_list(arguments, argc);
	
}