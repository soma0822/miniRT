NAME = miniRT

# main.c + find mini_rt/*/*.c | sed 's/\.c/\.c \\/g' | pbcopy

SRCS = srcs/main.c \
srcs/color/color.c \
srcs/color/color_calculator.c \
srcs/debug/ft_print_ambient.c \
srcs/debug/ft_print_camera.c \
srcs/debug/ft_print_color.c \
srcs/debug/ft_print_light.c \
srcs/debug/ft_print_object.c \
srcs/debug/ft_print_shader.c \
srcs/debug/ft_print_vector.c \
srcs/debug/ft_print_world.c \
srcs/gnl/get_next_line.c \
srcs/gnl/get_next_line_utils.c \
srcs/material/diffuse.c \
srcs/material/shading.c \
srcs/material/specular.c \
srcs/mlx_utils/close_hook.c \
srcs/mlx_utils/esc_hook.c \
srcs/parse/parse_ambient.c \
srcs/parse/parse_camera.c \
srcs/parse/parse_color.c \
srcs/parse/parse_cylinder.c \
srcs/parse/parse_error.c \
srcs/parse/parse_light.c \
srcs/parse/parse_plane.c \
srcs/parse/parse_sphere.c \
srcs/parse/parse_vector.c \
srcs/raytracing/find_intersection.c \
srcs/raytracing/find_intersection_cylinder.c \
srcs/raytracing/find_intersection_plane.c \
srcs/raytracing/find_intersection_sphere.c \
srcs/raytracing/shader_init.c \
srcs/read_map/init_element.c \
srcs/read_map/init_function.c \
srcs/read_map/parse_map.c \
srcs/read_map/read_map.c \
srcs/read_map/screen_new.c \
srcs/utils/ft_atof.c \
srcs/utils/ft_error.c \
srcs/utils/ft_free_twod_array.c \
srcs/utils/ft_isspace.c \
srcs/utils/ft_lstadd_back.c \
srcs/utils/ft_split_length.c \
srcs/vector/vector_advanced.c \
srcs/vector/vector_basic.c \



INCLUDE = include/

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -fsanitize=address -g
endif

LIB_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make $(MAKECMDGOALS) -C libft
	make -C minilibx_opengl_20191021
	$(CC) $(CFLAGS) $^ $(LIB_PATH) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o $@

$(OBJS_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make fclean -C libft
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: re

.PHONY: clean fclean re debug