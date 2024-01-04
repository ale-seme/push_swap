/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 20:55:43 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/04 17:25:46 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// typedef struct s_list
// {
//     void            *content;
//     struct s_list   *next;
// }                    t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = (NULL);
	return (new);
}

// int main(void)
// {
//     int value = 42;
//     t_list *pt = ft_lstnew(&value);
//     printf("%d", *((int *)pt->content));
//     return (0);
// }
