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

#include "../inc/so_long_bonus.h"

void	img_init(t_param *p)
{
	p->img_black = get_xpm_file("./img/black.xpm", p);
	p->img_wall = get_xpm_file("./img/wall.xpm", p);
	p->img_food = get_xpm_file("./img/food.xpm", p);
	p->img_por = get_xpm_file("./img/por.xpm", p);
	p->img_pac = get_xpm_file("./img/pacman/pac_closed.xpm", p);
	p->img_zero = get_xpm_file("./img/num/0.xpm", p);
	p->img_one = get_xpm_file("./img/num/1.xpm", p);
	p->img_two = get_xpm_file("./img/num/2.xpm", p);
	p->img_thr = get_xpm_file("./img/num/3.xpm", p);
	p->img_fou = get_xpm_file("./img/num/4.xpm", p);
	p->img_fiv = get_xpm_file("./img/num/5.xpm", p);
	p->img_six = get_xpm_file("./img/num/6.xpm", p);
	p->img_sev = get_xpm_file("./img/num/7.xpm", p);
	p->img_eig = get_xpm_file("./img/num/8.xpm", p);
	p->img_nin = get_xpm_file("./img/num/9.xpm", p);
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
			my_put_image(param, map[i][j], i, j);
			j++;
		}
		i++;
	}
	put_number(param);
}

void	my_put_image(t_param *p, char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(p->mlx, p->win, p->img_black, BIT * j, BIT * i);
	else if (c == '1')
		mlx_put_image_to_window(p->mlx, p->win, p->img_wall, BIT * j, BIT * i);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->win, p->img_food, BIT * j, BIT * i);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->win, p->img_por, BIT * j, BIT * i);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->win, p->img_pac, BIT * j, BIT * i);
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
