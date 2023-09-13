NAME = miniRT

# main.c + find mini_rt/*/*.c | sed 's/\.c/\.c \\/g' | pbcopy

SRCS = mini_rt/color/color.c \
mini_rt/color/color_calculator.c \
mini_rt/debug/ft_print_ambient.c \
mini_rt/debug/ft_print_camera.c \
mini_rt/debug/ft_print_color.c \
mini_rt/debug/ft_print_light.c \
mini_rt/debug/ft_print_object.c \
mini_rt/debug/ft_print_shader.c \
mini_rt/debug/ft_print_vector.c \
mini_rt/debug/ft_print_world.c \
mini_rt/gnl/get_next_line.c \
mini_rt/gnl/get_next_line_utils.c \
mini_rt/material/diffuse.c \
mini_rt/material/material_int.c \
mini_rt/material/shading.c \
mini_rt/material/specular.c \
mini_rt/matrix/matrix.c \
mini_rt/mlx_utils/close_hook.c \
mini_rt/mlx_utils/esc_hook.c \
mini_rt/parse/parse_ambient.c \
mini_rt/parse/parse_camera.c \
mini_rt/parse/parse_color.c \
mini_rt/parse/parse_cylinder.c \
mini_rt/parse/parse_error.c \
mini_rt/parse/parse_light.c \
mini_rt/parse/parse_plane.c \
mini_rt/parse/parse_sphere.c \
mini_rt/parse/parse_vector.c \
mini_rt/raytracing/find_intersection.c \
mini_rt/raytracing/find_intersection_cylinder.c \
mini_rt/raytracing/find_intersection_plane.c \
mini_rt/raytracing/find_intersection_sphere.c \
mini_rt/raytracing/shader_init.c \
mini_rt/read_map/init_element.c \
mini_rt/read_map/init_function.c \
mini_rt/read_map/parse_map.c \
mini_rt/read_map/read_map.c \
mini_rt/utils/ft_atof.c \
mini_rt/utils/ft_error.c \
mini_rt/utils/ft_free_twod_array.c \
mini_rt/utils/ft_isspace.c \
mini_rt/utils/ft_lstadd_back.c \
mini_rt/utils/ft_split_length.c \
mini_rt/vector/vector_advanced.c \
mini_rt/vector/vector_basic.c \






INCLUDE = include/

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -fsanitize=address -g
endif

ifeq ($(MAKECMDGOALS), 1)
SRCS += main.c screen_new.c
endif

ifeq ($(MAKECMDGOALS), 2)
SRCS += main2.c
endif

ifeq ($(MAKECMDGOALS), 3)
SRCS += main3.c
endif

LIB_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
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

1: re

2: re

3: re