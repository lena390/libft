/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:14:24 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/12 18:48:49 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	if (temp != NULL)
	{
		temp->next = NULL;
		temp->content = content;
	}
	return (temp);
}
