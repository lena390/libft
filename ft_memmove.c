/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:00:03 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/12 16:43:00 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_backwards(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	cdest = dest;
	csrc = src;
	while (n--)
		cdest[n] = csrc[n];
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	else if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
		return (ft_memcpy_backwards(dest, src, n));
}
