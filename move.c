/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:34:07 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/13 19:19:50 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	move_left(t_param *param, char map[][50])
{
	if (map[param->x][param->y - 1] == '1')
		return ;
	if (map[param->x][param->y - 1] == 'C')
		param->C--;
	if (map[param->x][param->y - 1] == 'E' && param->C == 0)
		exit(0);
	map[param->x][param->y] = '0';
	param->y -= 1;
	map[param->x][param->y] = 'P';
	param->move_cnt++;
}

void	move_right(t_param *param, char map[][50])
{
	if (map[param->x][param->y + 1] == '1')
		return ;
	if (map[param->x][param->y + 1] == 'C')
		param->C--;
	if (map[param->x][param->y + 1] == 'E' && param->C == 0)
		exit(0);
	map[param->x][param->y] = '0';
	param->y += 1;
	map[param->x][param->y] = 'P';
	param->move_cnt++;
}

void	move_up(t_param *param, char map[][50])
{
	if (map[param->x - 1][param->y] == '1')
		return ;
	if (map[param->x - 1][param->y] == 'C')
		param->C--;
	if (map[param->x - 1][param->y] == 'E' && param->C == 0)
		exit(1);
	map[param->x][param->y] = '0';
	param->x -= 1;
	map[param->x][param->y] = 'P';
	param->move_cnt++;
}

void	move_down(t_param *param, char map[][50])
{
	if (map[param->x + 1][param->y] == '1')
		return ;
	if (map[param->x + 1][param->y] == 'C')
		param->C--;
	if (map[param->x + 1][param->y + 1] == 'E' && param->C == 0)
		exit(0);
	map[param->x][param->y] = '0';
	param->x += 1;
	map[param->x][param->y] = 'P';
	param->move_cnt++;
}