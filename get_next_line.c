/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:21:52 by miphigen          #+#    #+#             */
/*   Updated: 2020/08/22 17:56:43 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_list		*create_add_new_list(t_gnl_list **lst, int fd)
{
	t_gnl_list *new;

	if (lst == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(t_gnl_list))))
		return (NULL);
	if (!(new->buf = malloc(BUFFER_SIZE + 1)))
	{
		free(new);
		return (NULL);
	}
	new->buf[0] = '\0';
	new->next = NULL;
	new->fd = fd;
	new->start = 0;
	new->next = *lst;
	new->bytes_read = 0;
	*lst = new;
	return (*lst);
}

t_gnl_list		*check_if_present(t_gnl_list *lst, int fd)
{
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

long int		find_eol(int *flag, char *buf, long int i, int bytes_read)
{
	while (i < bytes_read)
	{
		if (buf[i] == '\n')
		{
			*flag = 1;
			return (i);
		}
		else
			i++;
	}
	return (bytes_read);
}

int				gnl(int fd, t_gnl_list *st, char **line)
{
	char	*substr;
	int		flag;

	flag = 0;
	while (1)
	{
		if (flag == 1)
			return (st->bytes_read);
		if (!st->start)
		{
			st->start = 0;
			st->bytes_read = read(fd, st->buf, BUFFER_SIZE);
			if (st->bytes_read == 0)
				return (0);
			else if (st->bytes_read == -1)
				return (-1);
		}
		st->eol = find_eol(&flag, st->buf, st->start, st->bytes_read);
		substr = ft_substr(st->buf, st->start, (st->eol) - st->start);
		*line = gnl_strjoin(line, &substr);
		if (*line == NULL)
			return (-1);
		st->start = (st->eol >= st->bytes_read - 1) ? 0 : st->eol + 1;
	}
}

int				get_next_line(int fd, char **line)
{
	static t_gnl_list	*head_list;
	t_gnl_list			*ptr_list;
	int					res;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	if (!(ptr_list = check_if_present(head_list, fd)))
		if (!(ptr_list = create_add_new_list(&head_list, fd)))
		{
			return (-1);
		}
	*line = ft_strdup("");
	ptr_list->eol = 0;
	res = gnl(fd, ptr_list, line);
	if (res == 0)
		remove_list(&head_list, fd);
	else if (res == -1)
	{
		remove_list(&head_list, fd);
		*line != NULL ? free(*line) : 0;
		*line = NULL;
	}
	return (res);
}
