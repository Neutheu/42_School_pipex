# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 09:14:12 by nsouchal          #+#    #+#              #
#    Updated: 2024/02/13 12:59:17 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_FILE = main.c modified_split.c utils.c command.c

DIR_BUILD		=	.build/
DIR_SRCS 		= 	srcs/
DIR_HEADERS		=	includes/
DIR_LIBFT		=	libft/

HEADERFILES		=

OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
SRCS			=	$(addprefix $(DIR_SRCS),$(SRC_FILE))

FLAGS		=	-Wall -Werror -Wextra

CC = cc

.PHONY: all
all: libft $(NAME)

$(NAME): $(OBJS) $(DIR_LIBFT)libft.a
			$(CC) $(OBJS) $(DIR_LIBFT)libft.a -o $(NAME)

$(DIR_BUILD)%.o: %.c $(HEADERFILES) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -c $< -o $@

.PHONY: libft
libft:
		${MAKE} -C $(DIR_LIBFT)

.PHONY: clean
clean:
	${MAKE} -C $(DIR_LIBFT) clean
	rm -rf $(DIR_BUILD)

.PHONY: fclean
fclean: clean
		$(MAKE) -C $(DIR_LIBFT) fclean
		rm -rf $(NAME)

.PHONY: re
re: fclean
	$(MAKE) all
