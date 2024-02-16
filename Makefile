# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 22:38:22 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/16 22:49:01 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC_DIR = ./src
BONUS_DIR = ./bonus

SRC	= $(SRC_DIR)/map_pars.c $(SRC_DIR)/main.c $(SRC_DIR)/hook.c $(SRC_DIR)/move.c \
		$(SRC_DIR)/utils.c $(SRC_DIR)/map_check.c $(SRC_DIR)/map_check_utils.c $(SRC_DIR)/images.c

SRC_BONUS = $(BONUS_DIR)/map_pars_bonus.c $(BONUS_DIR)/main_bonus.c $(BONUS_DIR)/hook_bonus.c \
		$(BONUS_DIR)/move_bonus.c $(BONUS_DIR)/utils_bonus.c $(BONUS_DIR)/map_check_bonus.c \
		$(BONUS_DIR)/map_check_utils_bonus.c $(BONUS_DIR)/images_bonus.c

LIBDIR = ./libft/
LIBNAME = ft
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./inc

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
MAKE = make
RM = rm -f
CFLAGS = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))
ARFLAGS = rs
MLXFALGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c $(foreach D, $(INCDIRS), $(D)*.h)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(LIB) $(OBJS)
		$(CC) $(MLXFALGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME)

$(NAME_BONUS): $(NAME) $(OBJS_BONUS)
	$(CC) $(MLXFALGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBDIR) -l$(LIBNAME)

$(LIB):
	$(MAKE) -C $(LIBDIR) all
	
clean:
	$(MAKE) -C $(LIBDIR) clean
	${RM} $(SRC_DIR)/*.o $(BONUS_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME) $(NAME_BONUS)

re: fclean bonus

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus




