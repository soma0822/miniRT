NAME = miniRT
CC = cc
INCLUDES_DIR = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

SRCS = srcs/main.c \
	srcs/color/color_calculator.c \
	srcs/color/color.c \
	srcs/vector/vector_advanced.c \
	srcs/vector/vector_basic.c

OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
