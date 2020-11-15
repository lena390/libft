/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:32:07 by miphigen          #+#    #+#             */
/*   Updated: 2020/11/02 20:44:12 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_characters(char *str, char *set)
{
	while (*str != '\0' && ft_is_in_set(set, *str) == 1)
	{
		str++;
	}
	return (str);
}
