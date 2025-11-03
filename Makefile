# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cviel <cviel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 14:07:31 by mlouis            #+#    #+#              #
#    Updated: 2025/11/03 21:59:28 by cviel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := miniRT

INC := lib/libft/inc incs incs/data_structures lib/minilibx-linux lib/libmatrix/inc

LIB := ft m mlx Xext X11 z matrix

LIB_TARGET := 	libft/libft.a 					\
				libmatrix/libmatrix.a 			\
				minilibx-linux/libmlx_Linux.a 	\
				minilibx-libft/libmlx.a

BUILD_DIR := .build

SRC_DIR := srcs
SRC := 	parsing/parsing.c \
		# parsing/parsing_utils.c \ #
		parsing/parse_scene.c \
		parsing/fill_object.c \
		parsing/fill_scene.c \
		parsing/get_line.c \
		parsing/bvh_operations.c \
		parsing/find_box.c \
		parsing/get_types.c \
		parsing/get_variable.c \
		window/window_manager.c \
		main.c

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
	$(MAKE) -C lib/minilibx-linux

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(MAKE) clean -C lib/libft
	$(MAKE) clean -C lib/libmatrix
# 	$(MAKE) clean -C lib/minilibx-linux
	rm -rf $(OBJ) $(DEPS)
	rm -rf $(BUILD_DIR)

fclean:
	$(MAKE) fclean -C lib/libft
	$(MAKE) fclean -C lib/libmatrix
# 	$(MAKE) fclean -C lib/minilibx-linux
	rm -rf $(OBJ) $(DEPS) $(NAME)
	rm -rf $(BUILD_DIR)

re: fclean all
