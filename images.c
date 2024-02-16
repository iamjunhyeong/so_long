/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:54:37 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/16 21:00:24 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	img_init(t_param *p)
{
	p->img_black = mlx_xpm_file_to_image(p->mlx, "./img/black.xpm", &p->img_w, &p->img_h);
	p->img_wall = mlx_xpm_file_to_image(p->mlx, "./img/wall.xpm", &p->img_w, &p->img_h);
	p->img_food = mlx_xpm_file_to_image(p->mlx, "./img/pacdot_food.xpm", &p->img_w, &p->img_h);
	p->img_por = mlx_xpm_file_to_image(p->mlx, "./img/por.xpm", &p->img_w, &p->img_h);
	p->img_pac = mlx_xpm_file_to_image(p->mlx, "./img/pacman/pac_right.xpm", &p->img_w, &p->img_h);
	p->img_zero = mlx_xpm_file_to_image(p->mlx, "./img/num/0.xpm", &p->img_w, &p->img_h);
	p->img_one = mlx_xpm_file_to_image(p->mlx, "./img/num/1.xpm", &p->img_w, &p->img_h);
	p->img_two = mlx_xpm_file_to_image(p->mlx, "./img/num/2.xpm", &p->img_w, &p->img_h);
	p->img_thr = mlx_xpm_file_to_image(p->mlx, "./img/num/3.xpm", &p->img_w, &p->img_h);
	p->img_fou = mlx_xpm_file_to_image(p->mlx, "./img/num/4.xpm", &p->img_w, &p->img_h);
	p->img_fiv = mlx_xpm_file_to_image(p->mlx, "./img/num/5.xpm", &p->img_w, &p->img_h);
	p->img_six = mlx_xpm_file_to_image(p->mlx, "./img/num/6.xpm", &p->img_w, &p->img_h);
	p->img_sev = mlx_xpm_file_to_image(p->mlx, "./img/num/7.xpm", &p->img_w, &p->img_h);
	p->img_eig = mlx_xpm_file_to_image(p->mlx, "./img/num/8.xpm", &p->img_w, &p->img_h);
	p->img_nin = mlx_xpm_file_to_image(p->mlx, "./img/num/9.xpm", &p->img_w, &p->img_h);
}

void	put_img(char map[][50], t_param *p)
{
	int	i;
	int	j;

	mlx_clear_window(p->mlx, p->win);
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(p->mlx, p->win, p->img_black, BIT * j, BIT * i);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(p->mlx, p->win, p->img_wall, BIT * j, BIT * i);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(p->mlx, p->win, p->img_food, BIT * j, BIT * i);
			else if(map[i][j] == 'E')
				mlx_put_image_to_window(p->mlx, p->win, p->img_por, BIT * j, BIT * i);
			else if (map[i][j] == 'P')			
				mlx_put_image_to_window(p->mlx, p->win, p->img_pac, BIT * j, BIT * i);
			j++;
		}
		i++;
	}
	put_number(p);
}

void	*get_xpm(int num, t_param *p)
{
	if (num == 0)
		return (p->img_zero);
	if (num == 1)
		return (p->img_one);
	if (num == 2)
		return (p->img_two);
	if (num == 3)
		return (p->img_thr);
	if (num == 4)
		return (p->img_fou);
	if (num == 5)
		return (p->img_fiv);
	if (num == 6)
		return (p->img_six);
	if (num == 7)
		return (p->img_sev);
	if (num == 8)
		return (p->img_eig);
	return (p->img_nin);
}

void	put_number(t_param *p)
{
	int		cnt;
	int		tmp;
	int		i;
	int		w;
	int		h;

	w = 18;
	h = 10;
	if (p->move_cnt >= 9999)
	{
		ft_printf("TOO MANY MOVES!!");
		exit(1);
	}
	i = 3;
	cnt = p->move_cnt;
	while (i >= 0)
	{
		tmp = cnt % 10;
		cnt /= 10;
		mlx_put_image_to_window(p->mlx, p->win, get_xpm(tmp, p), w * i, h);
		i--;
	}
}
