/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 16:21:03 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/15 16:57:06 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_nodes(t_list *stack)
{
	t_list	*tp;
	
	while (stack && stack->next)
	{
		tp = stack;
		stack = stack->next;
		free(tp);
	}
	free(stack);
}

int	ft_right(t_list	*stack, long	nbr, char *str)
{
	t_list	*tp;
	int		i;

	tp = stack;
	i = 0;

	while (str[i])
	{
		if (!((ft_issign(str[i]) && ft_isdigit(str[i + 1]) && (i == 0 || !ft_isdigit(str[i - 1])))
			|| ft_isdigit(str[i])))
			return (free_all_nodes(stack), 0);
		i++;	
	}
	while (tp)
	{
		if (tp->content == nbr)
			return (free_all_nodes(stack), 0);
		tp = tp->next;
	}
	return (1);
}

t_list * ft_initialize_stack(char **argum, int argc)
{
	t_list	*tmp;
	t_list	*stack;
	int		i;
	long	nbr;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	stack = NULL;
	while(argum[i])
	{
		nbr = ft_atoi(argum[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_right(stack, nbr, argum[i] == 0))
		{
			write(2, "Error", 5);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&stack, tmp);
		tmp->index = -1;
		tmp->flag = -33;
		i++;	
	}
	return (stack);
}

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
	tab->stack_a = ft_inizialize_stack(arguments, argc);
	if (tab->stack_a == NULL)
		return (free(tab), -2);
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	choose_and_sort(tab);
}