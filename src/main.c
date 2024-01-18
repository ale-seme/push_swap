/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 16:21:03 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/18 19:42:10 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all_nodes(t_list *stack)
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

void	free_after_split(char **ss, char *str, int f)
{
	int	i;

	i = 0;
	if (ss == NULL || !ss[0] || f == 0)
	{
		return ;
	}
	if ((!ss[1] || ss[0][0] == '\0') && f == 1)
	{
		free(str);
		free(ss);
		return ;
	}
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
}

static int ft_ok(t_validation_params *params)
{
	t_list  *tp;
	int     i;

	tp = params->stack;
	i = 0;
	while (params->str[i])
	{
		if (!((ft_issign(params->str[i]) && ft_isdigit(params->str[i + 1])
				&& (i == 0 || !ft_isdigit(params->str[i - 1])))
			  || ft_isdigit(params->str[i])))
		{
			free_after_split(params->ss, params->str, params->f);
			return (free_all_nodes(params->stack), 0);
		}
		i++;
	}
	while (tp)
	{
		if (tp->content == params->n)
			return (free_after_split(params->ss, params->str, params->f), free_all_nodes(params->stack), 0);
		tp = tp->next;
	}
	return 1;
}



static t_list *ft_initialize(char **arg, int argc, int f)
{
	t_list *tmp;
	t_list *st;
	int i;
	long n;

	t_validation_params params;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	st = NULL;

	while (arg[i])
	{
		n = ft_atoi(arg[i]);
		params = (t_validation_params){st, n, arg[i], arg, f};
		if (n > INT_MAX || n < INT_MIN || ft_ok(&params) == 0)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}

		tmp = ft_lstnew(n);
		ft_lstadd_back(&st, tmp);
		tmp->index = -1;
		tmp->flag = -33;
		i++;
	}

	return (st);
}


int	main(int argc, char** argv)
{
	int flag;
	t_swap* tab;
	char** arguments;

	flag = 0;
	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if(arguments == NULL)
			return (free(tab), 0);
		flag = 1;
	}
	else 
		arguments = argv;
	tab->stack_a = ft_initialize(arguments, argc, flag);
	if (tab->stack_a == NULL)
		return (free(tab), -2); //be careful here try to find a way to free before
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	choose_and_sort(tab);
	free_after_split(arguments, arguments[0], flag);
}