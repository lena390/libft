/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:38:59 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 16:14:12 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return (char *)(&s[i]);
	}
	while (s[i])
	{
		if (s[i] == c)
			return (char *)(&s[i]);
		i++;
	}
	return (NULL);
}
