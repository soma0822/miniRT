NAME = miniRT

# main.c + find mini_rt/*/*.c | sed 's/\.c/\.c \\/g'

SRCS = main.c\
	mini_rt/utils/ft_error.c

INCLUDE = include/

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
endif

LIB_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -I$(INCLUDE) $^ $(LIB_PATH) -o $@

$(OBJS_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	make fclean -C libft
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all