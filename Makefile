SHELL		= /bin/sh

NAME		:= cub3D
BONUS		:= cub3D_bonus

CC			= cc
CFLAGS		:= -Wextra -Wall -Werror \
	#-Wunreachable-code -g -fsanitize=address,undefined \

## LIBS ##
LIBMLX		:= ./lib/MLX42
LIBFT		:= ./lib/libft
LINKER		:= -L "$(HOME)/.brew/opt/glfw/lib/" -ldl -lglfw -pthread -lm
LIBS		= ${LINKER} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

## HEADERS ##
HEADER_SRCS	:=	cub3d.h errors.h structures.h
HEADER_DIR	:=	inc/
HEADERS		= -I  $(HEADER_DIR) -I ${LIBMLX}/include -I ${LIBFT}

## SOURCE ##
SRCS		:= main.c free.c print.c exit.c \
	initialise.c \
	file_load.c file_elements.c file_elements_utils.c \
	user_input.c user_input_move.c user_input_check_corner.c\
	file_map.c utils_valid_map.c utils_ray_casting.c\
	minimap.c minimap_player.c user_input_minimap.c \
	ray_casting.c \
	world.c world_walls.c world_walls_colour.c \
	utils_joinfree.c utils_fill_map.c utils_move_player.c utils_dev.c \

SRC_DIR		:= src
BUILD_DIR	:= build
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

## HEADERS BONUS ##
HEADER_SRCS_BONUS	:=	cub3d_bonus.h errors_bonus.h structures_bonus.h
HEADER_DIR_BONUS	:=	inc_bonus/
HEADERS_BONUS		= -I  $(HEADER_DIR_BONUS) -I ${LIBMLX}/include -I ${LIBFT}

## BONUS ##
SRCS_BONUS		:= main_bonus.c free_bonus.c print_bonus.c exit_bonus.c \
	initialise_bonus.c \
	file_load_bonus.c file_elements_bonus.c file_elements_utils_bonus.c \
	user_input_bonus.c user_input_move_bonus.c user_input_check_corner_bonus.c\
	file_map_bonus.c utils_valid_map_bonus.c utils_ray_casting_bonus.c\
	minimap_bonus.c minimap_player_bonus.c user_input_minimap_bonus.c \
	ray_casting_bonus.c \
	world_bonus.c world_walls_bonus.c world_walls_colour_bonus.c \
	utils_joinfree_bonus.c utils_fill_map_bonus.c utils_move_player_bonus.c \
	utils_dev_bonus.c \
	sprite_bonus.c \

SRC_DIR_BONUS	:= src_bonus
BUILD_DIR_BONUS	:= build_bonus
SRCS_BONUS		:= $(addprefix $(SRC_DIR_BONUS)/,$(SRCS_BONUS))
OBJS_BONUS		:= $(patsubst $(SRC_DIR_BONUS)/%.c,$(BUILD_DIR_BONUS)/%.o,\
	$(SRCS_BONUS))

## TARGET ##
all	: libmlx libft $(NAME)
	@echo "${BMAG}Build successful!${NC}"

libmlx:
	@echo "${MAG}Building ${BMAG}MLX42...${NC}"
	@${MAKE} -C ${LIBMLX}
	@echo "${MAG}MLX42 build complete.${NC}"

libft:
	@echo "${MAG}Building ${BMAG}libft...${NC}"
	@${MAKE} -C ${LIBFT}
	@echo "${MAG}libft build complete.${NC}"

$(NAME): $(OBJS)
	@echo "${BCYA}Creating executable: $(NAME)${NC}"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "${MAG}$(NAME) build complete.${NC}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix $(HEADER_DIR), $(HEADER_SRCS))
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "${BGRE}Compiling:${NC} $(notdir $<) \
		${MAG}for ${BMAG}$(NAME)${NC} "

$(BONUS): libmlx libft $(OBJS_BONUS)
	@echo "${BCYA}Creating executable: $(BONUS)${NC}"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(HEADERS_BONUS) -o $(BONUS)
	@echo "${MAG}$(BONUS) build complete.${NC}"

$(BUILD_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(addprefix $(HEADER_DIR_BONUS),\
	 $(HEADER_SRCS_BONUS))
	@mkdir -p $(BUILD_DIR_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS_BONUS)
	@echo "${BGRE}Compiling:${NC} $(notdir $<) \
		${MAG}for ${BMAG}$(BONUS)${NC} "

bonus: $(BONUS)

clean	:
	@echo "$(RED)Cleaning$(NC)"
	rm -f $(OBJS)
	rm -rf $(BUILD_DIR)
	rm -f $(OBJS_BONUS)
	rm -rf $(BUILD_DIR_BONUS)
	${MAKE} -C ${LIBMLX} fclean
	${MAKE} -C ${LIBFT} fclean

fclean	: clean
	rm -f $(NAME) $(BONUS)

re		: fclean all

.PHONY	: all, clean, fclean, re, libmlx, libft, bonus
.DEFAULT_GOAL := all

## Colors ##
RED		:= \033[0;31m
BRED	:= \033[1;31m
GRE		:= \033[0;32m
BGRE	:= \033[1;32m
YEL		:= \033[0;33m
BYEL	:= \033[1;33m
BLU		:= \033[0;34m
BBLU	:= \033[1;34m
MAG		:= \033[0;35m
BMAG	:= \033[1;35m
CYA		:= \033[0;36m
BCYA	:= \033[1;36m
BWHI	:= \033[1;37m
NC		:= \033[0m
