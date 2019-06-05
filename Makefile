NAME = fractol

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCS = main.c

S_FOLD = $(addprefix srcs/, $(SRCS))

OBJS = $(S_FOLD:.c=.o)

L_FOLD = libft/

L_TARG = libft

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):$(OBJS) | $(L_TARG)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LIBMLX) -o $(NAME)
	@touch .gitignore
	@echo "*.o" > .gitignore
	@echo "*.a" >> .gitignore

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_TARG) clean
	@make -C $(M_FOLD) clean
	@rm -rf $(OBJS)

fclean:
	@make -C $(L_TARG) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all libft
