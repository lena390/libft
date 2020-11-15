/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:53:56 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 15:52:44 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;
	int					diff;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (i < n)
	{
		if ((diff = ptr1[i] - ptr2[i]))
			return (diff);
		i++;
	}
	return (0);
}
