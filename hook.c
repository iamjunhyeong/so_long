/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:00 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/13 20:39:45 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_param *param)
{
	static int	a;
	a = 0;

	if (keycode == KEY_W)
		move_up(param, param->map);
	else if (keycode == KEY_S)
		move_down(param, param->map);
	else if (keycode == KEY_A)
		move_left(param, param->map);
	else if (keycode == KEY_D)
		move_right(param, param->map);
	else if (keycode == KEY_ESC)
		exit (0);
	put_img(param->map, param);
	param->map[param->ex][param->ey] = 'E';
	mlx_put_image_to_window(param->mlx, param->win, param->img_portal, BIT * param->ey, BIT * param->ex);
	mlx_put_image_to_window(param->mlx, param->win, param->img_pacman, BIT * param->y, BIT * param->x);
	return (0);
}

void	hook(t_param *param)
{
	find_portal(param, param->map);
	mlx_hook(param->win, X_EVENT_KEY_RELEASE, 0, &key_press, param);
}
