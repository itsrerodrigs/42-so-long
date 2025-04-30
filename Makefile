# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 23:56:12 by renrodri          #+#    #+#              #
#    Updated: 2025/04/30 00:41:14 by renrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INC)
XFLAGS =  -lmlx -lXext -lX11
RM = rm -f

INC = ./include
LIBFT = ./libs/libft
MLX := ./libs/minilibx

GREEN=\033[0;32m
YELLOW=\033[0;33m
RESET=\033[0m

FILES = srcs/so_long.c \
		srcs/map_validation.c \
		srcs/validation_player.c \
		srcs/validation_structure.c \
		srcs/get_map_size.c \
		srcs/fill_map.c \
		srcs/print_assets.c \
		srcs/handle_memory.c \
		srcs/sprites.c \
		srcs/exit.c \
		srcs/game.c \
		srcs/movement.c 

OBJS = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(LIBFT) > /dev/null 2>&1
	@make -s -C $(MLX) 
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -L$(MLX) -o $(NAME) $(XFLAGS)
	@printf "$(GREEN)Success!$(RESET)\n"

clean:
	@make clean -C $(LIBFT) > /dev/null 2>&1
	@make clean -C $(MLX) > /dev/null 2>&1
	@$(RM) $(OBJS)
	@printf "$(YELLOW)clean Sucess!$(RESET)\n"

fclean: clean
	@make fclean -C $(LIBFT) > /dev/null 2>&1
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "$(YELLOW)fclean Success!$(RESET)\n"

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map.ber

re: fclean all

.PHONY: all clean fclean 