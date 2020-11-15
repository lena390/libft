/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:14:38 by miphigen          #+#    #+#             */
/*   Updated: 2020/11/15 20:03:43 by miphigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_metainfo
{
	char			flag;
	int				width;
	int				precision;
	char			specifier;
	int				len;
	int				sign;
}					t_metainfo;

void				print_metainfo(t_metainfo *f);
int					ft_printf(char *str, ...);

void				print_char(t_metainfo *f, unsigned char c, size_t *res);
void				print_str(t_metainfo *f, char *s, size_t *res);
void				print_nbr(t_metainfo *f, va_list *ap, size_t *res);

void				pf_putnbr(ssize_t nbr, char specifier, size_t *res);
void				pf_putchar_n(char c, ssize_t n, size_t *res);
void				pf_putstr(char	*s, int i, size_t *res);
char				*parse_metainfo(char *s, t_metainfo *f);

int					number_of_digits(ssize_t number, int base);
char				is_in_set(char c, char *set);
/*
** gnl
*/

typedef struct		s_gnl
{
	struct s_gnl	*next;
	int				fd;
	long int		start;
	char			*buf;
	long int		bytes_read;
	ssize_t			eol;
}					t_gnl_list;

int					get_next_line(int fd, char **line);
void				remove_list(t_gnl_list **head_ptr, int fd);
char				*gnl_strjoin(char **s1, char **s2);

int					ft_printf(char *str, ...);

/*
** libft
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
																size_t len);
int					ft_atoi(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(char c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
														void (*del)(void *));
char				*ft_skip_characters(char *str, char *set);
int					ft_is_in_set(const char *set, char c);

#endif
