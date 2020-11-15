/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:10:45 by miphigen          #+#    #+#             */
/*   Updated: 2020/07/14 16:28:39 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	print_char(t_metainfo *f, unsigned char c, size_t *res)
{
	f->len = 1;
	if (f->flag == '-')
	{
		pf_putchar_n(c, 1, res);
		pf_putchar_n(' ', f->width - 1, res);
	}
	else if (f->flag == '0')
	{
		pf_putchar_n('0', f->width - f->len, res);
		pf_putchar_n(c, 1, res);
	}
	else
	{
		pf_putchar_n(' ', f->width - 1, res);
		pf_putchar_n(c, 1, res);
	}
}

void	print_str(t_metainfo *f, char *s, size_t *res)
{
	ssize_t	strlength;

	s = s == NULL ? "(null)" : s;
	strlength = (ssize_t)ft_strlen(s);
	if (f->precision == -1)
		f->len = strlength;
	else
		f->len = f->precision < strlength ? f->precision : strlength;
	if (f->flag == '-')
	{
		pf_putstr(s, f->len, res);
		pf_putchar_n(' ', f->width - f->len, res);
	}
	else if (f->flag == '0')
	{
		pf_putchar_n('0', f->width - f->len, res);
		pf_putstr(s, f->len, res);
	}
	else
	{
		pf_putchar_n(' ', f->width - f->len, res);
		pf_putstr(s, f->len, res);
	}
}

void	print_ptr(t_metainfo *f, ssize_t l, int checkbox, size_t *res)
{
	int	nbr;

	nbr = f->width - (f->precision > f->len ? f->precision : f->len) - 2;
	if (f->flag == '-')
	{
		pf_putstr("0x", 2, res);
		pf_putchar_n('0', f->precision - f->len, res);
		checkbox == 1 ? pf_putnbr(l, f->specifier, res) : 0;
		pf_putchar_n(' ', nbr, res);
	}
	else if (f->flag == '0' && f->precision == 0)
	{
		pf_putstr("0x", 2, res);
		pf_putchar_n('0', f->width - f->len - 2, res);
		checkbox == 1 ? pf_putnbr(l, f->specifier, res) : 0;
	}
	else
	{
		pf_putchar_n(' ', nbr, res);
		pf_putstr("0x", 2, res);
		pf_putchar_n('0', f->precision - f->len, res);
		checkbox == 1 ? pf_putnbr(l, f->specifier, res) : 0;
	}
}

void	print_nbr_2(t_metainfo *f, ssize_t l, int checkbox, size_t *res)
{
	int	nbr;

	nbr = f->width - (f->precision > f->len ? f->precision : f->len) - f->sign;
	if (f->flag == '-')
	{
		f->sign == 1 ? pf_putchar_n('-', 1, res) : 1;
		pf_putchar_n('0', f->precision - f->len, res);
		checkbox == 1 ? pf_putnbr(l, f->specifier, res) : 0;
		pf_putchar_n(' ', nbr, res);
	}
	else if (f->flag == '0' && f->precision == 0)
	{
		f->sign == 1 ? pf_putchar_n('-', 1, res) : 1;
		pf_putchar_n('0', f->width - f->len - f->sign, res);
		checkbox == 1 ? pf_putnbr(l, f->specifier, res) : 0;
	}
	else
	{
		pf_putchar_n(' ', nbr, res);
		f->sign == 1 ? pf_putchar_n('-', 1, res) : 1;
		pf_putchar_n('0', f->precision - f->len, res);
		checkbox == 1 ? pf_putnbr(l, f->specifier, res) : 0;
	}
}

void	print_nbr(t_metainfo *f, va_list *ap, size_t *res)
{
	ssize_t		l;
	int			checkbox;

	l = 0;
	if (f->specifier == 'x' || f->specifier == 'X' || f->specifier == 'u')
		l = va_arg(*ap, unsigned int);
	else if (f->specifier == 'd' || f->specifier == 'i')
		l = va_arg(*ap, int);
	else
		l = va_arg(*ap, ssize_t);
	l < 0 ? (f->sign = 1) : 0;
	f->sign == 1 ? (l *= -1) : 0;
	f->specifier == 'p' ? (f->sign = 2) : 0;
	if (l == 0 && f->precision == 0)
		f->len = 0;
	else if (f->specifier == 'd' || f->specifier == 'i' || f->specifier == 'u')
		f->len = number_of_digits(l, 10);
	else
		f->len = number_of_digits(l, 16);
	checkbox = (f->precision == 0 && l == 0) ? 0 : 1;
	f->precision = f->precision == -1 ? 0 : f->precision;
	f->specifier == 'p' ? print_ptr(f, l, checkbox, res) :
		print_nbr_2(f, l, checkbox, res);
}
