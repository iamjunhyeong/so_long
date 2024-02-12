/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:00 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/12 22:27:08 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

void	param_init(t_param *param, char map[][50])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 50)
	{
		while (j < 50 && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	param->x = i;
	param->y = j;
}

int	key_press(int keycode, t_param *param)
{
	static int	a;
	a = 0;

	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit (0);
	printf("x: %d, y: %d\n", param->x, param->y); 
	return (0);
}

void	hook(t_vars *vars, t_img *img, char map[][50])
{
	t_param	param;

	if (!img)
		return ;
	param_init(&param, map);
	mlx_hook(vars->win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
}
