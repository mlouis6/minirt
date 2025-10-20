# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 15:08:26 by mlouis            #+#    #+#              #
#    Updated: 2025/10/20 09:07:16 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := libmatrix.a

INCS := matrix.h error.h
INC_DIR := inc ../libft/inc

# LIBS := ft

LIBS_TARGET := ../libft/libft.a

SRC_DIR := src
SRCS := matrix.c			\
		matrix_utils.c		\
		matrix_operations.c \
		vector_operations.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR := .build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

LIB_DIR := ../libft/inc

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := $(addprefix -I,$(INC_DIR)) -MMD -MP
LDFLAGS = $(addprefix -L,$(dir $(LIBS_TARGET)))
# LDLIBS := $(addprefix -l,$(LIBS))
MAKEFLAGS += --no-print-directory

all: $(NAME)

libft:
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBS_TARGET)
	ar rcs $(NAME) $(OBJS)

$(LIBS_TARGET):
	$(MAKE) -C ../libft

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(MAKE) clean -C ../libft
	rm -f $(OBJS) $(DEPS)
	rm -f -r $(BUILD_DIR)

fclean:
	$(MAKE) fclean -C ../libft
	rm -f $(OBJS) $(DEPS) $(NAME)
	rm -f -r $(BUILD_DIR)

re: fclean all
