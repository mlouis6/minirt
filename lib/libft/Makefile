# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 17:05:43 by mlouis            #+#    #+#              #
#    Updated: 2025/11/04 15:02:44 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := libft.a

INC := inc

SRC_DIR := src
SRCS := ft_isalpha.c				\
		ft_isdigit.c				\
		ft_isalnum.c				\
		ft_isascii.c				\
		ft_isprint.c				\
		ft_isspace.c				\
		ft_strlen.c					\
		ft_memset.c					\
		ft_bzero.c					\
		ft_memcpy.c					\
		ft_memmove.c				\
		ft_strlcpy.c				\
		ft_strlcat.c				\
		ft_toupper.c				\
		ft_tolower.c				\
		ft_strchr.c					\
		ft_strrchr.c				\
		ft_strncmp.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_strnstr.c				\
		ft_atoi.c					\
		ft_strtol.c					\
		ft_calloc.c					\
		ft_strdup.c					\
		ft_substr.c					\
		ft_strjoin.c				\
		ft_strtrim.c				\
		ft_split.c					\
		free_arr.c					\
		ft_itoa.c					\
		ft_strmapi.c				\
		ft_striteri.c				\
		ft_putchar_fd.c				\
		ft_putstr_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\
		ft_lstnew.c					\
		ft_lstadd_front.c			\
		ft_lstsize.c				\
		ft_lstlast.c				\
		ft_lstadd_back.c			\
		ft_lstdelone.c				\
		ft_lstclear.c				\
		ft_lstiter.c				\
		ft_lstmap.c					\
		ft_printf.c					\
		ft_printf_utils.c			\
		ft_putnbr_base_fd.c			\
		ft_putnbr_positive_fd.c		\
		get_next_line.c				\
		get_next_line_utils.c		\
		find_char.c					\
		ft_strtod.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR := .build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := $(addprefix -I,$(INC)) -MMD -MP
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)
	rm -f -r $(BUILD_DIR)

fclean:
	rm -f $(OBJS) $(DEPS) $(NAME)
	rm -f -r $(BUILD_DIR)

re: fclean all

