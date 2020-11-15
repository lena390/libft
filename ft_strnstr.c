/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:40:36 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/15 20:33:48 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int j;

	if (little[0] == '\0')
		return (char *)(big);
	i = 0;
	while (big[i] != '\0' && i != len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i] == little[j] && i != len && big[i] != '\0')
			{
				i++;
				j++;
			}
			if (little[j] == '\0')
				return (char *)(&big[i - j]);
		}
		else
			i++;
	}
	return (NULL);
}
