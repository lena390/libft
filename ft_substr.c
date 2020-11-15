/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:39:52 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/15 17:29:49 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;

	if (s == NULL)
		return (NULL);
	else if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(substr = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		substr[i] = (char)s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
