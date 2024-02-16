# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:01:09 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/16 22:00:34 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = ./

SRC	= map_pars.c main.c hook.c move.c utils.c map_check.c map_check_utils.c images.c

LIBDIR = ./libft/
LIBNAME = ft 
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./
OBJS = $(SRC:.c=.o)
INC = ./so_long.h

CC = cc
MAKE = make
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(INC)
MLXFALGS = -L./mlx -lmlx -framework OpenGL -framework AppKit 
ARFLAGS = rs

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(LIB) $(OBJS) 
		$(CC) $(MLXFALGS) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME)
		touch $@

$(LIB):
	$(MAKE) -C $(LIBDIR) all
	
clean:
	$(MAKE) -C $(LIBDIR) clean
	${RM} $(SRC_DIR)/*.o 

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME) 

re: fclean all

.PHONY: all clean fclean re




