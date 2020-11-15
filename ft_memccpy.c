/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 01:37:40 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 16:08:39 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*chdest;
	const char		*chsrc;
	char			uc;

	chdest = dest;
	chsrc = src;
	uc = (char)c;
	while (n)
	{
		*chdest = *chsrc;
		chdest++;
		if (*chsrc == uc)
			return (chdest);
		chsrc++;
		n--;
	}
	return (NULL);
}
