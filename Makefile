# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 12:47:33 by oohnivch          #+#    #+#              #
#    Updated: 2024/09/11 15:55:59 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#									Variables								   #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lXext -lmlx -lX11
HEADER = -I./includes
HEADER_BONUS = -I./includes_bonus/
NAME = so_long
BONUS = so_long_bonus

LIBDIR = ./libft
LIB = $(LIBDIR)/libft.a

NORMAL = \033[0m
GREEN = \033[1;32m
PURPLE = \033[1;35m
RED = \033[0;31m
YELLOW = \033[0;33m

# **************************************************************************** #
#									Source Files							   #
# **************************************************************************** #

SRC_PATH = src/
SRC_PATH_BONUS = src_bonus/
OBJ_PATH = obj/
OBJ_PATH_BONUS = obj_bonus/

SRC = main.c annihilate.c game_logic.c init_utils.c map.c \
	  render_utils.c enemy_logic.c keyhook.c map_utils.c \
	  enemy_movement.c image_utils.c positions.c general_utils.c 

SRC_BONUS = annihilate_bonus.c main_bonus.c game_logic_bonus.c \
			init_utils_bonus.c map_bonus.c render_utils_bonus.c \
			enemy_logic_bonus.c keyhook_bonus.c map_utils_bonus.c \
			enemy_movement_bonus.c image_utils_bonus.c \
			positions_bonus.c general_utils_bonus.c 

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS = $(addprefix $(OBJ_PATH_BONUS), $(OBJ_BONUS))

# **************************************************************************** #
#									Rules									   #
# **************************************************************************** #

all: $(OBJ_PATH) $(NAME)

bonus: $(OBJ_PATH_BONUS) $(BONUS)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) -o $(NAME) 
	@echo "\n$(GREEN)******** $(NAME) Created! ********$(NORMAL)\n"

$(BONUS): $(OBJS_BONUS) $(LIB)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(LIB) -o $(BONUS) 
	@echo "\n$(PURPLE)******** $(BONUS) Created! ********$(NORMAL)\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(LIB)
	@if ! $(CC) $(CFLAGS) -o $@ -c $< $(HEADER) 2> error.txt; then\
		echo "$(RED)!!!!!!!! ERROR !!!!!!!!$(NORMAL)"; \
		echo "$(YELLOW)Error caused by $<$(NORMAL)\n"; \
		sed '$$d' error.txt; \
		echo "\n$(RED)Aborting makefile........$(NORMAL)"; \
		exit 1; \
	fi

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c $(LIB)
	@if ! $(CC) $(CFLAGS) -o $@ -c $< $(HEADER_BONUS) 2> error.txt; then\
		echo "$(RED)!!!!!!!! ERROR !!!!!!!!$(NORMAL)"; \
		echo "$(YELLOW)Error caused by $<$(NORMAL)\n"; \
		sed '$$d' error.txt; \
		echo "\n$(RED)Aborting makefile........$(NORMAL)"; \
		exit 1; \
	fi

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH_BONUS):
	@mkdir $(OBJ_PATH_BONUS)

$(LIB):
	@make -C $(LIBDIR) all

clean:
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH_BONUS)
	@rm -f error.txt
	@echo "$(YELLOW)Deleting $(words $(OBJ) $(OBJ_BONUS) error.txt) object file(s) $(NORMAL)"
	@echo "$(GREEN)Deletion success! $(NORMAL)"

fclean:
	@make -C $(LIBDIR) fclean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH_BONUS)
	@rm -f $(NAME) $(BONUS) error.txt
	@echo "$(YELLOW)Deleting $(NAME) $(BONUS) and $(words $(OBJ) error.txt) object file(s) $(NORMAL)" 
	@echo "$(GREEN)Deletion success! $(NORMAL)"

re: fclean all

.PHONY: all bonus clean fclean re
