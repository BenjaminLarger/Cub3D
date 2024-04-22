SHELL		= /bin/sh

NAME		:= cub3d

LIBMLX		:= ./lib/MLX42
LIBFT		:= ./lib/libft

CC			= cc
CFLAGS		:= -Wextra -Wall -Werror \
	-Wunreachable-code -g -fsanitize=address,undefined \

## LIBS ##
LINKER		:= -L "$(HOME)/.brew/opt/glfw/lib/" -ldl -lglfw -pthread -lm
LIBS		= ${LINKER} ${LIBMLX}/build/libmlx42.a ${LIBFT}/libft.a

## HEADERS ##
HEADER_SRCS	:=	cub3d.h
HEADER_DIR	:=	inc/
HEADERS		= -I  $(HEADER_DIR) -I ${LIBMLX}/include -I ${LIBFT}

## SOURCE ##
SRCS		:= main.c

SRC_DIR		:= src
BUILD_DIR	:= build
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))


## TARGET ##
all	: libmlx libft $(NAME)
	@echo "${BMAG}Build successful!${NC}"

libmlx:
	@echo "${MAG}Building ${BMAG}MLX42...${NC}"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "${MAG}MLX42 build complete.${NC}"

libft:
	@echo "${MAG}Building ${BMAG}libft...${NC}"
	${MAKE} -C ${LIBFT}
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

clean	:
	@echo "$(RED)Cleaning$(NC)"
	rm -f $(OBJS)
	rm -rf $(BUILD_DIR)
	rm -rf $(LIBMLX)/build
	${MAKE} -C ${LIBFT} fclean

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all, clean, fclean, re, libmlx, libft
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