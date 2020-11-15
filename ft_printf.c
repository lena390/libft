/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:26:26 by miphigen          #+#    #+#             */
/*   Updated: 2020/07/14 16:26:35 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_metainfo_to_zero(t_metainfo *f)
{
	f->flag = 0;
	f->width = 0;
	f->precision = -1;
	f->specifier = 0;
	f->len = 0;
	f->sign = 0;
}

void	print_by_format_2(t_metainfo *f, va_list *ap, size_t *res)
{
	if (f->flag == '0' && is_in_set(f->specifier, "scp") != 0)
		f->flag = f->precision == -1 ? '0' : 0;
	if (f->specifier == '%')
		print_char(f, '%', res);
	else if (f->specifier == 'c')
		print_char(f, (unsigned char)va_arg(*ap, int), res);
	else if (f->specifier == 's')
		print_str(f, va_arg(*ap, char *), res);
	else
		print_nbr(f, ap, res);
}

char	*print_by_format(char *str, t_metainfo *f, va_list *ap, size_t *res)
{
	char		*ptr;

	ptr = str;
	str = parse_metainfo(str, f);
	if (f->width == -2 && f->specifier != 0)
	{
		f->width = va_arg(*ap, int);
		if (f->width < 0)
		{
			f->width *= -1;
			f->flag = '-';
		}
	}
	if (f->precision == -2 && f->specifier != 0)
		f->precision = va_arg(*ap, int);
	f->precision = f->precision < -1 ? -1 : f->precision;
	if (f->specifier == 0)
	{
		while (ptr != str)
			pf_putchar_n(*ptr++, 1, res);
	}
	else
		print_by_format_2(f, ap, res);
	return (str);
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	size_t		res;
	t_metainfo	f;

	va_start(ap, str);
	res = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			set_metainfo_to_zero(&f);
			str = print_by_format(++str, &f, &ap, &res);
		}
		else
			pf_putchar_n(*str++, 1, &res);
	}
	va_end(ap);
	return (res);
}
