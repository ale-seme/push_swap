/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 16:21:03 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/19 18:08:58 by ale           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_nod(t_list *stack)
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

void	fr_s(char **ss, char *str, int f)
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

static int	ft_ok(t_validation_params *par)
{
	t_list	*tp;
	int		i;

	tp = par->stack;
	i = 0;
	while (par->str[i])
	{
		if (!((ft_issign(par->str[i]) && ft_isdigit(par->str[i + 1])
					&& (i == 0 || !ft_isdigit(par->str[i - 1])))
				|| ft_isdigit(par->str[i]))
			|| (par->n > INT_MAX || par->n < INT_MIN))
		{
			fr_s(par->ss, par->str, par->f);
			return (free_nod(par->stack), 0);
		}
		i++;
	}
	while (tp)
	{
		if (tp->content == par->n)
			return (fr_s(par->ss, par->str, par->f), free_nod(par->stack), 0);
		tp = tp->next;
	}
	return (1);
}

static t_list	*ft_initialize(char **arg, int argc, int f)
{
	t_list				*tmp;
	t_list				*st;
	int					i;
	long				n;
	t_validation_params	par;

	i = ft_set_start(argc);
	st = NULL;
	while (arg[i])
	{
		n = ft_atoi(arg[i]);
		par = (t_validation_params){st, n, arg[i], arg, f};
		if (ft_ok(&par) == 0)
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

int	main(int argc, char **argv)
{
	int		flag;
	t_swap	*tab;
	char	**arg;

	flag = 0;
	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (arg == NULL)
			return (free(tab), 0);
		flag = 1;
	}
	else
		arg = argv;
	tab->stack_a = ft_initialize(arg, argc, flag);
	if (tab->stack_a == NULL)
		return (free(tab), -2);
	ft_continue_main(tab);
	return (fr_s(arg, arg[0], flag), free_nod(tab->stack_a), free(tab), 0);
}
