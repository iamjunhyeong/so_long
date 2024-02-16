/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:34:07 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/16 21:18:54 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	finish_game(t_param *param)
{
	ft_printf("FINISH!!\n");
	ft_printf("Total Moves: %d\n", param->move_cnt + 1);
	exit(0);
}

void	move_left(t_param *p, char map[][50])
{
	char	*str;

	str = "./img/pacman/pac_left.xpm";
	p->img_pac = mlx_xpm_file_to_image(p->mlx, str, &p->img_w, &p->img_h);
	if (map[p->x][p->y - 1] == '1')
		return ;
	if (map[p->x][p->y - 1] == 'C')
		p->c--;
	if (map[p->x][p->y - 1] == 'E' && p->c == 0)
		finish_game(p);
	map[p->x][p->y] = '0';
	p->y -= 1;
	map[p->x][p->y] = 'P';
	p->move_cnt++;
}

void	move_right(t_param *p, char map[][50])
{
	char	*str;

	str = "./img/pacman/pac_right.xpm";
	p->img_pac = mlx_xpm_file_to_image(p->mlx, str, &p->img_w, &p->img_h);
	if (map[p->x][p->y + 1] == '1')
		return ;
	if (map[p->x][p->y + 1] == 'C')
		p->c--;
	if (map[p->x][p->y + 1] == 'E' && p->c == 0)
		finish_game(p);
	map[p->x][p->y] = '0';
	p->y += 1;
	map[p->x][p->y] = 'P';
	p->move_cnt++;
}

void	move_up(t_param *p, char map[][50])
{
	char	*str;

	str = "./img/pacman/pac_up.xpm";
	p->img_pac = mlx_xpm_file_to_image(p->mlx, str, &p->img_w, &p->img_h);
	if (map[p->x - 1][p->y] == '1')
		return ;
	if (map[p->x - 1][p->y] == 'C')
		p->c--;
	if (map[p->x - 1][p->y] == 'E' && p->c == 0)
		finish_game(p);
	map[p->x][p->y] = '0';
	p->x -= 1;
	map[p->x][p->y] = 'P';
	p->move_cnt++;
}

void	move_down(t_param *p, char map[][50])
{
	char	*str;

	str = "./img/pacman/pac_down.xpm";
	p->img_pac = mlx_xpm_file_to_image(p->mlx, str, &p->img_w, &p->img_h);
	if (map[p->x + 1][p->y] == '1')
		return ;
	if (map[p->x + 1][p->y] == 'C')
		p->c--;
	if (map[p->x + 1][p->y + 1] == 'E' && p->c == 0)
		finish_game(p);
	map[p->x][p->y] = '0';
	p->x += 1;
	map[p->x][p->y] = 'P';
	p->move_cnt++;
}
