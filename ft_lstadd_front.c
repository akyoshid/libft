/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:55:13 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/23 19:12:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Adds the node ’new’ at the beginning of the list.
// (t_list **lst) expects the address of the head pointer of a linked list.
// The double pointer lets the function
// directly change the start of the linked list,
// ensuring that the head pointer in the calling function
// always points to the first node of the list.

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// static void	ft_printlst(t_list *lst)
// {
// 	if (lst == NULL)
// 	{
// 		printf("lst is NULL.\n");
// 		return ;
// 	}
// 	while (lst != NULL)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("1");
// 	ft_lstadd_front(&head, ft_lstnew("2"));
// 	ft_lstadd_front(&head, ft_lstnew("3"));
// 	ft_lstadd_front(&head, ft_lstnew("4"));
// 	// ft_lstadd_front(NULL, ft_lstnew("2"));
// 	// head = NULL;
// 	// ft_lstadd_front(&head, ft_lstnew("2"));
// 	ft_printlst(head);
// 	return (0);
// }
