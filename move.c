/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:34:07 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/15 18:32:35 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	finish_game(t_param *param)
{
	ft_printf("Total Moves: %d\n", param->move_cnt + 1);
	exit(0);
}

void	move_left(t_param *param, char map[][50])
{
	if (map[param->x][param->y - 1] == '1')
		return ;
	if (map[param->x][param->y - 1] == 'C')
		param->c--;
	if (map[param->x][param->y - 1] == 'E' && param->c == 0)
		finish_game(param);
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
		param->c--;
	if (map[param->x][param->y + 1] == 'E' && param->c == 0)
		finish_game(param);
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
		param->c--;
	if (map[param->x - 1][param->y] == 'E' && param->c == 0)
		finish_game(param);
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
		param->c--;
	if (map[param->x + 1][param->y + 1] == 'E' && param->c == 0)
		finish_game(param);
	map[param->x][param->y] = '0';
	param->x += 1;
	map[param->x][param->y] = 'P';
	param->move_cnt++;
}