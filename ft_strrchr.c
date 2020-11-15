/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:02:35 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/08 22:36:48 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*res;
	int			i;

	i = 0;
	res = NULL;
	if (c == '\0')
		return (ft_strchr(s, c));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			res = &s[i];
		i++;
	}
	return (char *)(res);
}
