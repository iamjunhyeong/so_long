/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:45:08 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/12 21:51:55 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BIT	32

void	put_img(t_vars *vars, t_img *img, char map[][50])
{
	int	i;
	int	j;

	i = 0;
	while (i < 50 && map[i][j] != -1)
	{
		j = 0;
		while (j < 50 && map[i][j] != -1)
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img1, BIT * j, BIT * i);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img2, BIT * j, BIT * i);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img3, BIT * j, BIT * i);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img4, BIT * j, BIT * i);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img6, BIT * j, BIT * i);
			j++;
		}
		i++;
	}
}

void	set_img(t_vars *vars, t_img *img, char map[][50])
{
	img->img1 = mlx_xpm_file_to_image(vars->mlx, "./images/black.xpm", &img->img_width, &img->img_height);
	img->img2 = mlx_xpm_file_to_image(vars->mlx, "./images/wall.xpm", &img->img_width, &img->img_height);
	img->img3 = mlx_xpm_file_to_image(vars->mlx, "./images/pacdot_food.xpm", &img->img_width, &img->img_height);
	img->img4 = mlx_xpm_file_to_image(vars->mlx, "./images/portal.xpm", &img->img_width, &img->img_height);
	img->img5 = mlx_xpm_file_to_image(vars->mlx, "./images/B/ghost_left1.xpm", &img->img_width, &img->img_height);
	img->img6 = mlx_xpm_file_to_image(vars->mlx, "./images/pac_open_right.xpm", &img->img_width, &img->img_height);

	put_img(vars, img, map);
}

int main(void)
{
	char	map[50][50];
	t_img	img;
	t_vars	vars;

	img.img_width = 1920;
	img.img_height = 1080;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, img.img_width, img.img_height, "Hellow World!");
	set_map(map);
	set_img(&vars, &img, map);

	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(vars.mlx);
	return (0);
}
