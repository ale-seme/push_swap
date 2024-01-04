/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 21:41:34 by asemerar      #+#    #+#                 */
/*   Updated: 2023/10/26 18:01:08 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	if (!lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new;
	}
}

// int main()
// {
//     // Test 1: Clear an Empty List
//     t_list *empty_list = NULL;
//     ft_lstclear(&empty_list, del);
//     if (empty_list == NULL)
//         printf("Test Case 1: (Empty List cleared good .\n");
//     else
//         printf("Test Case 1: List not cleared.\n");
//     // Test Case 2: Clear a List with One Element
//     t_list *list1 = malloc(sizeof(t_list));
//     int data1 = 42;
//     list1->content = &data1;
//     list1->next = NULL;
//     ft_lstclear(&list1, del);
//     if (list1 == NULL)
//         printf("Test Case 2: List of one element cleared good.\n");
//     else
//         printf("Test Case 2: List not cleared as expected.\n");
//     // Test Case 3: Clear a List with Multiple Elements
//     t_list *list2 = malloc(sizeof(t_list));
//     int data2 = 10;
//     list2->content = &data2;
//     t_list *second_node = malloc(sizeof(t_list));
//     int data3 = 20;
//     second_node->content = &data3;
//     list2->next = second_node;
//     second_node->next = NULL;
//     ft_lstclear(&list2, del);
//     if (list2 == NULL)
//         printf("Test Case 3: List cleared good (Multiple Elements).\n");
//     else
//         printf("Test Case 3: List not cleared.\n");
//     return 0;
// }