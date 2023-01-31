# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:10:07 by dsas              #+#    #+#              #
#    Updated: 2023/01/31 19:07:33 by dsas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = pipex
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g
DEBUG = -fsanitize=address
LEAKS = leaks -atExit -- ./push-swap

BONUS = checker
BONUS_MAIN = checker.c

MAIN = push_swap.c

# Libraries
LIBFTPRINTF_A = libft/libft.a

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFTPRINTF = libft

# Source and object files
SRCS =	pipex.c path_find.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Rules
all: $(NAME)

#$(DEBUG)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTPRINTF) bonus
	mv $(LIBFTPRINTF_A) libft.a
	$(CC) $(CFLAGS) $(OBJ) -L. -lft -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ)
	$(MAKE) -C $(LIBFTPRINTF) bonus
	mv $(LIBFTPRINTF_A) libft.a
	@$(CC) $(CFLAGS) $^ $(BONUS_MAIN) -L. -lft -o $@

clean:
	rm -rf $(OBJ)
	rm -rf libft.a
	$(MAKE) clean -C $(LIBFTPRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re
