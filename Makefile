NAME = miniRT

# main.c + find mini_rt/*/*.c | sed 's/\.c/\.c \\/g'

SRCS = main.c\
mini_rt/debug/ft_print_ambient.c \
mini_rt/debug/ft_print_camera.c \
mini_rt/debug/ft_print_color.c \
mini_rt/debug/ft_print_light.c \
mini_rt/debug/ft_print_object.c \
mini_rt/debug/ft_print_vector.c \
mini_rt/debug/ft_print_world.c \
mini_rt/gnl/get_next_line.c \
mini_rt/gnl/get_next_line_utils.c \
mini_rt/parse/parse_ambient.c \
mini_rt/parse/parse_camera.c \
mini_rt/parse/parse_color.c \
mini_rt/parse/parse_cylinder.c \
mini_rt/parse/parse_error.c \
mini_rt/parse/parse_light.c \
mini_rt/parse/parse_plane.c \
mini_rt/parse/parse_sphere.c \
mini_rt/parse/parse_vector.c \
mini_rt/read_map/init_element.c \
mini_rt/read_map/init_function.c \
mini_rt/read_map/parse_map.c \
mini_rt/read_map/read_map.c \
mini_rt/utils/ft_atof.c \
mini_rt/utils/ft_error.c \
mini_rt/utils/ft_free_twod_array.c \
mini_rt/utils/ft_isspace.c \
mini_rt/utils/ft_lstadd_back.c \
mini_rt/utils/ft_split_length.c

INCLUDE = include/

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -fsanitize=address -g
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

debug: re