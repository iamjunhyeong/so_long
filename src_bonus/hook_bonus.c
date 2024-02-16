/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:00 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/16 22:51:37 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	key_press(int keycode, t_param *p)
{
	void	*mlx;

	mlx = p->mlx;
	if (keycode == KEY_W)
		move_up(p, p->map);
	else if (keycode == KEY_S)
		move_down(p, p->map);
	else if (keycode == KEY_A)
		move_left(p, p->map);
	else if (keycode == KEY_D)
		move_right(p, p->map);
	else if (keycode == KEY_ESC)
		end_game(p);
	put_img(p->map, p);
	p->map[p->ex][p->ey] = 'E';
	mlx_put_image_to_window(mlx, p->win, p->img_por, BIT * p->ey, BIT * p->ex);
	mlx_put_image_to_window(mlx, p->win, p->img_pac, BIT * p->y, BIT * p->x);
	return (0);
}

void	hook(t_param *p)
{
	find_portal(p, p->map);
	mlx_hook(p->win, X_EVENT_KEY_RELEASE, 0, &key_press, p);
}
