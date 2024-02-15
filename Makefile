# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:01:09 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/15 18:52:39 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = checker

SRC_DIR = ./
CHECKER_DIR = ./check

SRC	= map_pars.c main.c hook.c move.c utils.c map_check.c map_check_utils.c

LIBDIR = ./libft/
LIBNAME = ft 
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./inc/

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
MAKE = make
RM = rm -f
CFLAGS = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))
ARFLAGS = rs

all: $(NAME)

%.o: %.c $(foreach D, $(INCDIRS), $(D)*.h)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(LIB) $(OBJS)
		$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME)
# arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c

$(NAME_BONUS): $(NAME) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBDIR) -l$(LIBNAME)

$(LIB):
	$(MAKE) -C $(LIBDIR) all
	
clean:
	$(MAKE) -C $(LIBDIR) clean
	${RM} $(SRC_DIR)/*.o $(CHECKER_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus




