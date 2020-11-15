/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:08:22 by miphigen          #+#    #+#             */
/*   Updated: 2020/07/14 16:29:57 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		number_of_digits(ssize_t number, int base)
{
	int	res;

	res = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		res++;
		number /= base;
	}
	return (res);
}

char	is_in_set(char c, char *set)
{
	while (*set != '\0')
		if (*set++ == c)
			return (c);
	return (0);
}
