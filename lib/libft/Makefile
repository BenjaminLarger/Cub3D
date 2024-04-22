SHELL	= /bin/sh

NAME	= libft.a

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
NC	:= \033[0m

CC	= gcc
AR	= ar
CFLAGS	+= -Wall -Wextra -Werror -I .

SRC_FILES = ft_atoi.c ft_isalpha.c ft_isprint.c ft_memset.c ft_strlcpy.c \
	ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_strchr.c ft_strlen.c \
	ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_strlcat.c ft_strcmp.c \
	ft_strncmp.c ft_tolower.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
	ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c \
	ft_lst_new_node.c ft_lst_get_size.c ft_lst_get_last_node.c \
	ft_lst_add_back.c ft_lst_add_front.c \
	ft_lst_delete_one.c ft_lst_delete_all.c ft_lst_apply_all.c ft_lst_map.c \
	ft_get_next_line.c ft_get_next_line_utils.c

BUILD_DIR := build
SRCS := $(addprefix $(BUILD_DIR)/,$(SRC_FILES))
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(AR) rcs $(NAME) $(OBJS)
	@echo "${CYAN}Creating archive: $(NAME)${NC}"

$(BUILD_DIR)/%.o: %.c libft.h ft_get_next_line.h
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiling:${NC} $(notdir $<)"

.PHONY: all clean fclean re
all : $(NAME)
clean :
	@echo "$(RED)Cleaning$(NC)"
	rm -f $(OBJS)
	rm -rf build/
fclean : clean
	rm -f $(NAME)
re : fclean all

.DEFAULT_GOAL := all
