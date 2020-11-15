/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:09:17 by miphigen          #+#    #+#             */
/*   Updated: 2020/05/11 16:09:18 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		divider;
	char	c;
	long	l;

	l = (long)n;
	if (l == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	divider = 1000000000;
	while (l / divider == 0)
		divider /= 10;
	while (divider)
	{
		c = (l / divider) + '0';
		ft_putchar_fd(c, fd);
		l = l % divider;
		divider /= 10;
	}
}
