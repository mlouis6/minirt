# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 15:08:26 by mlouis            #+#    #+#              #
#    Updated: 2025/11/13 14:57:48 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := libvector.a

INCS := ft_vector.h
INC_DIR := inc ../libft/inc

LIBS_TARGET := ../libft/libft.a

SRC_DIR := src
SRCS := ft_vector_init.c \
		ft_vector_copy.c \
		ft_vector_free.c \
		ft_vector_add_single.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR := .build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

LIB_DIR := ../libft/inc

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := $(addprefix -I,$(INC_DIR)) -MMD -MP
LDFLAGS = $(addprefix -L,$(dir $(LIBS_TARGET)))
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
