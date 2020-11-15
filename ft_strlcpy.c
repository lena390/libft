/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:19:35 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 16:24:15 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	else if (size == 1 || ft_strlen(src) == 0)
		dst[0] = '\0';
	else
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			dst[i] = '\0';
		}
	while (src[i])
		i++;
	return (i);
}
