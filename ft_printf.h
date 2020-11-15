/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:25:22 by miphigen          #+#    #+#             */
/*   Updated: 2020/08/13 17:06:37 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_metainfo
{
	char		flag;
	int			width;
	int			precision;
	char		specifier;
	int			len;
	int			sign;
}				t_metainfo;

void			print_metainfo(t_metainfo *f);
int				ft_printf(char *str, ...);

void			print_char(t_metainfo *f, unsigned char c, size_t *res);
void			print_str(t_metainfo *f, char *s, size_t *res);
void			print_nbr(t_metainfo *f, va_list *ap, size_t *res);

void			pf_putnbr(ssize_t nbr, char specifier, size_t *res);
void			pf_putchar_n(char c, ssize_t n, size_t *res);
void			pf_putstr(char	*s, int i, size_t *res);
char			*parse_metainfo(char *s, t_metainfo *f);

int				number_of_digits(ssize_t number, int base);
char			is_in_set(char c, char *set);

#endif
