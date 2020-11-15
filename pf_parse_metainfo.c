/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1_parse_metainfo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:08:01 by miphigen          #+#    #+#             */
/*   Updated: 2020/07/14 16:28:02 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_precision(char **str, t_metainfo *f)
{
	char	*s;

	s = *str;
	f->flag == '0' ? (f->flag = 0) : 0;
	if (*s == '*')
	{
		f->precision = -2;
		s++;
	}
	else
	{
		f->precision = ft_atoi(s);
		f->precision = f->precision < 0 ? -1 : f->precision;
		while (*s == '0')
			s++;
		s = f->precision == 0 ? s : s + number_of_digits(f->precision, 10);
	}
	*str = s;
}

char	*parse_metainfo(char *s, t_metainfo *f)
{
	while (*s != '\0' && (*s == '0' || *s == '-'))
		if (f->flag != '-')
			f->flag = *s++ == '-' ? '-' : '0';
		else
			s++;
	if (*s == '*')
	{
		f->width = -2;
		s++;
	}
	else if ((f->width = ft_atoi(s)) != 0)
		s += number_of_digits(f->width, 10);
	if (*s == '.')
	{
		s++;
		parse_precision(&s, f);
	}
	f->specifier = is_in_set(*s, "cspdiuxX%");
	*s == '\0' ? 0 : s++;
	return (s);
}
