/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:04:21 by miphigen          #+#    #+#             */
/*   Updated: 2020/08/17 18:23:28 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = -1;
	while (s1[i] != '\0' && start == -1)
	{
		if (ft_is_in_set(set, s1[i]) == 0)
			start = i;
		i++;
	}
	end = start;
	while (s1[i] != '\0')
	{
		if (ft_is_in_set(set, s1[i]) == 0)
			end = i;
		i++;
	}
	if (start == -1)
		return (ft_strdup(""));
	else
		return (ft_substr(s1, (unsigned int)start, (size_t)(end - start + 1)));
}
