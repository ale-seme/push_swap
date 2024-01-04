/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 12:53:22 by asemerar      #+#    #+#                 */
/*   Updated: 2023/10/26 18:57:05 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// // function to be applied to each element in the list
// void *map_function(void *content)
// {
//     // duble the content if it's an integer
//     int *int_ptr = (int *)content;
//     int *result = (int *)malloc(sizeof(int));
//     if (!result)
//         return NULL;
//     *result = (*int_ptr) * 2;
//     return result;
// }
// function to delete content
// void del(void *content)
// {
//     free(content);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_node;
	void	*p1;

	new = (NULL);
	while (lst)
	{
		p1 = f(lst->content);
		if (!p1)
		{
			ft_lstclear(&new, del);
			break ;
		}
		new_node = ft_lstnew(p1);
		if (!new_node)
		{
			ft_lstclear(&new, del);
			del(p1);
			break ;
		}
		ft_lstadd_back(&new, new_node);
		lst = lst->next;
	}
	return (new);
}

// int main()
// {
//     // i will create a linked list all nulls content
//     t_list *list = ft_lstnew((void *)1);
//     list->next = ft_lstnew((void *)2);
//     list->next->next = ft_lstnew((void *)3);
//     // Apply ft_lstmap with the map_function
//     t_list *new_list = ft_lstmap(list, map_function, del);
//     // Display the original and mapped lists
//     t_list *temp = new_list;
//     printf("Original List: ");
//     while (list)
//     {
//         printf("%d -> ", *((int *)list->content));
//         list = list->next;
//     }
//     printf("NULL\n");
//     printf("Mapped List: ");
//     while (temp)
//     {
//         printf("%d -> ", *((int *)temp->content));
//         temp = temp->next;
//     }
//     printf("NULL\n");
//     // this is to Clean up memory
//     ft_lstclear(&list, del);
//     ft_lstclear(&new_list, del);
//     return 0;
// }