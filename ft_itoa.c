/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:25:59 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 16:15:04 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		amount_of_digits(int nbr)
{
	int	res;

	if (nbr < 0)
		res = 2;
	else
		res = 1;
	while (nbr / 10)
	{
		res++;
		nbr /= 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = amount_of_digits(n);
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	i = len - 1;
	while (n / 10)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	res[i] = n + '0';
	return (res);
}
