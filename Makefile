# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 14:07:31 by mlouis            #+#    #+#              #
#    Updated: 2026/01/09 16:44:51 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := miniRT

INC := lib/libft/inc incs incs/data_structures lib/libmatrix/inc lib/lib_vector/inc lib/minilibx-linux

LIB := ft matrix vector m mlx Xext X11 z

LIB_TARGET := 	libft/libft.a 					\
				libmatrix/libmatrix.a 			\
				lib_vector/libvector.a			\
				minilibx-linux/libmlx_Linux.a 	\
				minilibx-libft/libmlx.a

BUILD_DIR := .build

SRC_DIR := srcs
SRC := 	parsing/get_line.c \
		parsing/get_types.c \
		parsing/parse_line.c \
		parsing/parsing.c \
		parsing/split_line.c \
		ray/ray.c \
		ray/light.c \
		ray/collisions_check.c \
		window/window_manager.c \
		window/viewport.c \
		window/viewport_dir.c \
		window/color.c \
		window/display.c \
		parsing/free_all.c \
		main.c \

SRC := $(SRC:%=$(SRC_DIR)/%)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS = $(OBJ:.o=.d)

CC := cc
CFLAGS := -Wall -Werror -Wextra -g3
CPPFLAGS := $(addprefix -I,$(INC)) -MMD -MP
LDFLAGS = $(addprefix -Llib/,$(dir $(LIB_TARGET)))
LDLIBS := $(addprefix -l,$(LIB))
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJ) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

$(LIB_TARGET):
	$(MAKE) -C lib/libft
	$(MAKE) -C lib/libmatrix
	$(MAKE) -C lib/lib_vector
	$(MAKE) -C lib/minilibx-linux

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(MAKE) clean -C lib/libft
	$(MAKE) clean -C lib/libmatrix
	$(MAKE) clean -C lib/lib_vector
	$(MAKE) clean -C lib/minilibx-linux
	rm -rf $(OBJ) $(DEPS)
	rm -rf $(BUILD_DIR)

fclean:
	$(MAKE) fclean -C lib/libft
	$(MAKE) fclean -C lib/libmatrix
	$(MAKE) fclean -C lib/lib_vector
	$(MAKE) clean -C lib/minilibx-linux
	rm -rf $(OBJ) $(DEPS) $(NAME)
	rm -rf $(BUILD_DIR)

re: fclean all
