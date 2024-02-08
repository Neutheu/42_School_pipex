# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:39:14 by nsouchal          #+#    #+#              #
#    Updated: 2024/02/05 10:46:42 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS:.c=.o)

DIR_FTPRINTF	=	ft_printf/

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

CC = cc

HEADERFILES = libft.h


all: ft_printf $(NAME)

$(NAME): $(OBJ) $(DIR_FTPRINTF)libftprintf.a
			cd $(DIR_FTPRINTF) && cp libftprintf.a ../$(NAME)
			ar rcs $(NAME) $(OBJ)
			ranlib $(NAME)

%.o: %.c $(HEADERFILES) Makefile
	$(CC) $(FLAGS) -c $< -o $@
			
ft_printf:
				$(MAKE) -C $(DIR_FTPRINTF)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(DIR_FTPRINTF) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(DIR_FTPRINTF) fclean

bonus :
	$(MAKE) $(NAME) SRC="$(SRC) $(BONUS)"

re: fclean all

.PHONY: all clean fclean bonus re ft_printf
