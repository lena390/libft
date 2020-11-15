/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:20:09 by miphigen          #+#    #+#             */
/*   Updated: 2020/08/13 15:25:54 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** changes in behaviour: 1. returns 0 only if str2 == NULL;
 ** 2. frees the memory space occupied by parameters 1 and 2
*/

char	*gnl_strjoin(char **str1, char **str2)
{
	int		len;
	char	*res;
	int		i;
	char	*s1;
	char	*s2;

	s1 = *str1;
	s2 = *str2;
	if (!s2 || !s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		res[i++] = *s1++;
	while (*s2 != '\0')
		res[i++] = *s2++;
	free(*str1);
	free(*str2);
	res[i] = '\0';
	return (res);
}

void	remove_list(t_gnl_list **head_ptr, int fd)
{
	t_gnl_list	*prev_lst;
	t_gnl_list	*lst;

	lst = *head_ptr;
	if (lst->fd == fd)
	{
		*head_ptr = lst->next;
		free(lst->buf);
		free(lst);
		return ;
	}
	while (lst != NULL)
	{
		if (lst->fd == fd)
		{
			prev_lst->next = lst->next;
			free(lst->buf);
			free(lst);
			return ;
		}
		prev_lst = lst;
		lst = lst->next;
	}
}
