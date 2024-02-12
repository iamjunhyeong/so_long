/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:00 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/12 21:52:53 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2



void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
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

int hook(t_vars *vars,)
{
	t_param	param;

	param_init(&param);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "mlx_pj");
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(vars.mlx);
}
