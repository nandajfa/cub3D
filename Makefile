NAME		= cub3D

CC			= gcc
RM			= rm -rf
MKDIR		= mkdir -p

vpath %.c src ./src/build_data ./src/key_hook ./src/raycasting

FLAGS = -Wall -Wextra -Werror
MLX_LIB = -lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT_PATH = ./libs/libft
LIBFT = ${LIBFT_PATH}/libft.a

HEAD = -I./include/

MAIN = main.c

INIT = init.c init_aux.c

DESTROY = destroy.c destroy_aux.c

BUILD_DATA =	build_data.c build_tools.c read_file.c check_contents_file.c extract_contents.c \
				check_refined_texture.c check_refined_color.c check_refined_map_aux.c \
				check_refined_map.c load_texture.c extract_contents_aux.c \

RENDER =	render.c raycasting.c project_rays.c intersection.c ray_tools.c render_3d.c \
			draw_wall.c offset.c \

TOOLS =	key_hook.c get_player.c moviments.c

SRC =	main.c \
		init.c init_aux.c destroy.c destroy_aux.c \
		build_data.c build_tools.c read_file.c check_contents_file.c extract_contents.c \
		check_refined_texture.c check_refined_color.c check_refined_map.c check_refined_map_aux.c \
		load_texture.c extract_contents_aux.c \
		render.c raycasting.c project_rays.c intersection.c ray_tools.c render_3d.c \
		offset.c draw_wall.c\
		key_hook.c get_player.c moviments.c \

OBJ_DIR	 =	obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: ${NAME}

${NAME}: $(OBJ) ${OBJ_DIR} ${LIBFT}
		@$(CC) $(FLAGS ) $(HEAD) -no-pie -o $(NAME) $(OBJ) $(MLX_LIB) $(LIBFT)
		@ echo "\e[0;34m"
		@ echo "=========================="
		@ echo "  Compiled successfully!"
		@ echo "=========================="
		@ echo "\033[1;0m"

${LIBFT}:
		@ make -C ${LIBFT_PATH}

$(OBJ_DIR)/%.o: %.c
	@ ${MKDIR} $(OBJ_DIR)
	@ $(CC) $(FLAGS) $(HEAD) -c $< -o $@

norm:
	@norminette ./src ./include | grep "Error" | cat

clean:
		@ ${RM} ${OBJ_DIR}
		@make clean -C $(LIBFT_PATH)
		@ echo "\e[0;32m  Objects removed. \033[1;0m"

fclean:		clean
			@${RM} ${NAME}
			@ echo " \e[0;32m Program has been cleaned!\033[1;0m"

re:			fclean all

.PHONY: 	all clean fclean re