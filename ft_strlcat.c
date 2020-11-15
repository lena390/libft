/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:06:00 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/13 23:43:33 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	j;
	int	i_size;
	int	dst_size;

	i_size = (int)size;
	dst_size = ft_strlen(dst);
	i = 0;
	j = 0;
	while (i < i_size && dst[i] != '\0')
		i++;
	if (i == i_size)
		return (i_size + ft_strlen(src));
	while (i <= i_size - 2 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_size + ft_strlen(src));
}
