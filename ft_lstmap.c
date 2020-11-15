/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 13:41:49 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/12 19:21:30 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		delete(t_list *lst)
{
	free(lst->content);
	free(lst);
}

static void	remove_chain(t_list **lst)
{
	t_list	*ptr;
	t_list	*head;

	if (lst == NULL || *lst == NULL)
		return ;
	head = *lst;
	while (head != NULL)
	{
		ptr = head->next;
		delete(head);
		head = ptr;
	}
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ptr;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	ptr = head;
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			remove_chain(&head);
			return (NULL);
		}
		ptr->next = tmp;
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (head);
}
