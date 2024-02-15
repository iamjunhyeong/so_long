/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:27:26 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/15 18:23:36 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_param param;

	if (argc != 2)
		print_error(1);
	param_init(&param, argv[1]);
	set_map(param.map, &param);
	put_img(param.map, &param);
	hook(&param);
	mlx_loop(param.mlx);
	return (0);
}

void	param_init(t_param *param, char *map)
{
	param->map_name = map;
	param->img_width = 1920;
	param->img_height = 1080;
	param->c = 0;
	param->e = 0;
	param->p = 0;
	param->row = 0;
	param->col = 0;
	param->str = NULL;
	param->x = 0;
	param->y = 0;
	param->move_cnt = 0;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->img_width, param->img_height, "Hellow World!");
	param->img_black = mlx_xpm_file_to_image(param->mlx, "./images/black.xpm", &param->img_width, &param->img_height);
	param->img_wall = mlx_xpm_file_to_image(param->mlx, "./images/wall.xpm", &param->img_width, &param->img_height);
	param->img_food = mlx_xpm_file_to_image(param->mlx, "./images/pacdot_food.xpm", &param->img_width, &param->img_height);
	param->img_portal = mlx_xpm_file_to_image(param->mlx, "./images/portal.xpm", &param->img_width, &param->img_height);
	param->img_ghost = mlx_xpm_file_to_image(param->mlx, "./images/B/ghost_left1.xpm", &param->img_width, &param->img_height);
	param->img_pacman = mlx_xpm_file_to_image(param->mlx, "./images/pac_open_right.xpm", &param->img_width, &param->img_height);
}

void	put_img(char map[][50], t_param *param)
{
	int	i;
	int	j;

	mlx_clear_window(param->mlx, param->win);
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(param->mlx, param->win, param->img_black, BIT * j, BIT * i);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(param->mlx, param->win, param->img_wall, BIT * j, BIT * i);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(param->mlx, param->win, param->img_food, BIT * j, BIT * i);
			else if(map[i][j] == 'E')
				mlx_put_image_to_window(param->mlx, param->win, param->img_portal, BIT * j, BIT * i);
			else if (map[i][j] == 'P')			
				mlx_put_image_to_window(param->mlx, param->win, param->img_pacman, BIT * j, BIT * i);
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
// void	print_map(char map[][50])
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < 50)
// 	{
// 		j = 0;
// 		while (j < 50 && map[i][j] != -1)
// 		{
// 			printf("%d",map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }
