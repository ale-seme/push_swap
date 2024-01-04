/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 18:52:25 by asemerar      #+#    #+#                 */
/*   Updated: 2023/10/26 13:41:43 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// typedef struct s_list
// {
//     void            *content;
//     struct s_list   *next;
// }                    t_list;
// void del(void * content)
// {
//     // free(&content);
//     // *(int *)content = 0;
//     // printf("%d", *(int *)content);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

// int main(void)
// {
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     int n1 = 3;
//     node1->content = &n1;
//     node1->next = node2;
//     node2->content = NULL;
//     node2->next = NULL;
//     printf("before using the function: %d ", *((int *)node1->content));
//     ft_lstdelone(node1, *del);
//     printf("the code has been correctly freed ");
//     // free(node1);
//     free(node2);
//     return (0);
// }
