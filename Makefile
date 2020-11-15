#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: miphigen <miphigen@student.21-school.ru>   +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020/05/05 22:13:38 by miphigen          #+#    #+#             *#
#*   Updated: 2020/11/15 20:04:35 by miphigen         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

FLAGS = -Wall -Wextra -Werror

SRC = 	ft_is_in_set.c\
		ft_skip_characters.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_printf.c\
		pf_parse_metainfo.c\
		pf_prints.c\
		pf_putchar_and_co.c\
		pf_utils.c\
		ft_isspace.c


OBJ = $(SRC:.c=.o)

NAME = libft.a

HEADER = libft.h

.PHONY : clean fclean re all bonus

all: $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		@ar rcs $(NAME) $^
		@cp libft.* ~/
		@echo "libft ok"

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
