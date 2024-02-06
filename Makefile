# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 18:21:29 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/06 19:53:28 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	
# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
all:
	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit hook.c
	./a.out