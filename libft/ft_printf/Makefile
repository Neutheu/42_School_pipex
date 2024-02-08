# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 09:38:53 by nsouchal          #+#    #+#              #
#    Updated: 2024/02/05 10:52:50 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c printf_c.c printf_d_i.c printf_s.c printf_u.c printf_xlow_xupp.c \
		printf_p.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = cc

HEADERFILES = ft_printf.h

all: $(NAME)
	
$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(HEADERFILES) Makefile
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
