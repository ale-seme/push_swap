/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 21:39:15 by asemerar      #+#    #+#                 */
/*   Updated: 2023/10/26 13:43:19 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void f(void *content)
// {
//     printf("Content of the node is: %d", (*(int *)(content)));
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// int main(void)
// {
//     t_list * node1 = malloc(sizeof(t_list));
//     t_list * node2 = malloc(sizeof(t_list));
//     t_list * node3 = malloc(sizeof(t_list));
//     int n1= 14;
//     int n2= 15;
//     int n3= 16;
//     node1->content = &n1;
//     node1->next = node2;
//     node2->content = &n2;
//     node2->next = node3;
//     node3->content = &n3;
//     node3->next = NULL;
//     ft_lstiter(node1, f);
//     return (0);
// }