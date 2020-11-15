/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:57:40 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 15:58:31 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_bytescpy(void *dest, const void *src, size_t n)
{
	char			*chdest;
	const char		*chsrc;

	chdest = (char*)dest;
	chsrc = (char*)src;
	while (n != 0)
	{
		*chdest = *chsrc;
		chdest++;
		chsrc++;
		n--;
	}
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	long long			*ldest;
	const long long		*lsrc;
	size_t				llsize;

	if (!dest && !src)
		return (NULL);
	llsize = sizeof(long long);
	ldest = dest;
	lsrc = src;
	if (n >= llsize)
	{
		while (n / llsize >= 1)
		{
			*ldest = *lsrc;
			ldest++;
			lsrc++;
			n -= llsize;
		}
	}
	if (n != 0)
	{
		ft_bytescpy(ldest, lsrc, n);
	}
	return (dest);
}
