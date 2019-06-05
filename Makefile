# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 07:58:15 by mhernand          #+#    #+#              #
#    Updated: 2019/06/05 16:22:53 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCS = main.c\
	   start.c

S_FOLD = $(addprefix srcs/, $(SRCS))

OBJS = $(S_FOLD:.c=.o)

L_FOLD = libft/

L_TARG = libft

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):$(OBJS) | $(L_TARG)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LIBMLX) -g -o $(NAME)
	@touch .gitignore
	@echo "*.o" > .gitignore
	@echo "*.a" >> .gitignore

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_TARG) clean
	@make -C $(M_FOLD) clean
	rm -rf $(OBJS)

fclean: clean
	@make -C $(L_TARG) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all libft
