# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 07:58:15 by mhernand          #+#    #+#              #
#    Updated: 2019/07/03 17:00:09 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = includes/fractol.h

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCS = main.c\
	   setfractol.c\
	   start.c\
	   refresh.c\
	   touch.c\
	   touchtwomuch.c\
	   triggers.c\
	   mandelbrot.c\
	   julia.c\
	   fern.c\
	   koch.c\
	   burn.c\
	   glynn.c\
	   doubleburning.c\
	   tricorn.c\
	   sierpinski.c\
	   color.c

OBJS = $(SRCS:.c=.o)

L_FOLD = libft/

L_TARG = libft

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

superfast:
	@make -j8 all

all: 
	@make $(NAME)

$(NAME):$(OBJS) | $(L_TARG)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LIBMLX) -o $(NAME)
	@touch .gitignore
	@echo "*.o" > .gitignore
	@echo "*.a" >> .gitignore

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $< -c

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_TARG) clean
	@make -C $(M_FOLD) clean
	@rm -rf $(OBJS)
	@echo "Fract'ol is clean !"

fclean: clean
	@make -C $(L_TARG) fclean
	@rm -rf $(NAME)
	@echo "... and fclean too !"

re: fclean all

.PHONY: all clean fclean all libft
