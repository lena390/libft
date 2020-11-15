/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:41:30 by miphigen          #+#    #+#             */
/*   Updated: 2020/08/17 22:06:15 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_word_length(const char *s, char c)
{
	int len;

	len = 1;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void		free_res(char **res)
{
	size_t	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char		**extend_capacity(char **res, size_t size, size_t *capacity)
{
	char	**res2;
	size_t	i;

	res2 = (char **)ft_calloc(size * 2, sizeof(char *));
	if (res2 == NULL)
	{
		free_res(res);
		return (NULL);
	}
	*capacity = size * 2;
	i = 0;
	while (i < size)
	{
		res2[i] = res[i];
		i++;
	}
	free(res);
	return (res2);
}

static char		**add(char **res, size_t size, char *ptr, size_t *capacity)
{
	if ((size < *capacity - 1))
	{
		res[size] = ptr;
		return (res);
	}
	else if ((size = *capacity - 1))
	{
		res = extend_capacity(res, size, capacity);
		if (res == NULL)
		{
			free(ptr);
			return (NULL);
		}
	}
	return (add(res, size, ptr, capacity));
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	s_index;
	size_t	size;
	size_t	capacity;
	size_t	len;

	if (s == NULL)
		return (NULL);
	s_index = 0;
	size = 0;
	capacity = 3;
	if (!(array = (char **)ft_calloc(capacity, sizeof(char *))))
		return (NULL);
	while (s[s_index] != '\0')
		if (s[s_index] != c)
		{
			len = find_word_length(&s[s_index], c);
			if (!(array = add(array, size++,
				ft_substr(s, s_index, len), &capacity)))
				return (NULL);
			s_index += len;
		}
		else
			s_index++;
	return (array);
}
