/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar_and_co.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:02:57 by miphigen          #+#    #+#             */
/*   Updated: 2020/07/14 16:29:16 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_putstr(char *s, int i, size_t *res)
{
	if (i < 0)
		while (*s != '\0')
			pf_putchar_n(*s++, 1, res);
	else
		while (*s != '\0' && i--)
			pf_putchar_n(*s++, 1, res);
}

void	pf_putchar_n(char c, ssize_t n, size_t *res)
{
	while (n > 0)
	{
		write(1, &c, 1);
		*res += 1;
		n--;
	}
}

void	pf_putnbr_decimal(ssize_t n, char c, size_t *res)
{
	int		divider;
	long	l;

	l = (long)n;
	if (l == 0)
	{
		pf_putchar_n('0', 1, res);
		return ;
	}
	else if (l < 0)
	{
		pf_putchar_n('-', 1, res);
		l *= -1;
	}
	divider = 1000000000;
	while (l / divider == 0)
		divider /= 10;
	while (divider)
	{
		c = (l / divider) + '0';
		pf_putchar_n(c, 1, res);
		l = l % divider;
		divider /= 10;
	}
}

void	pf_putnbr_hex(ssize_t i, char specifier, size_t *res)
{
	int	remainder;

	if (i >= 16)
		pf_putnbr_hex(i / 16, specifier, res);
	remainder = i % 16;
	specifier = specifier == 'X' ? 'A' : 'a';
	if (remainder >= 10)
		pf_putchar_n(specifier + remainder - 10, 1, res);
	else
		pf_putnbr_decimal(remainder, 0, res);
}

void	pf_putnbr(ssize_t nbr, char specifier, size_t *res)
{
	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		pf_putnbr_decimal(nbr, specifier, res);
	else if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		pf_putnbr_hex(nbr, specifier, res);
}
