/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:55:36 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/13 21:48:04 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
int	ind_check(int ind)
{
	if (0 <= ind && ind < 50)
		return (1);
	return (0);
}

void	dfs_init(t_dfs *vars)
{
	vars->dx[0] = 1;
	vars->dx[1] = -1;
	vars->dx[2] = 0;
	vars->dx[3] = 0;
	vars->dy[0] = 0;
	vars->dy[1] = 0;
	vars->dy[2] = 1;
	vars->dy[3] = -1;
	vars->x = 0;
	vars->y = 0;
}

void	dfs(char visited[][50], t_param *param, char map[][50], t_head *head)
{
	t_dfs	v;

	dfs_init(&v);

	add_new_node(head, param->x, param->y);
	ft_printf("hi\n");
	visited[param->x][param->y] = 1;
	while (head->size)
	{
		v.i = 0;
		v.tmp = stack_pop(head);
		v.x = v.tmp->x;
		v.y = v.tmp->y;
		while (v.i < 4)
		{
			if (!ind_check(v.x + v.dx[v.i]) || !ind_check(v.y + v.dy[v.i]))
				continue ;
			if (visited[v.x + v.dx[v.i]][v.y + v.dy[v.i]] || map[v.x + v.dx[v.i]][v.y + v.dy[v.i]] == '1')
				continue ;
			add_new_node(head, v.x + v.dx[v.i], v.y + v.dy[v.i]);
			visited[v.x + v.dx[v.i]][v.y + v.dy[v.i]] = 1;
			v.i++;
		}
	}
}

void	check_visited(char visited[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			if (!visited[i][j])
				print_error(1);
			j++;
		}
		i++;
	}
}

int	check_map(char map[][50], t_param *param)
{
	char	visited[50][50];
	t_head	*head;

	head = NULL;
	if (param->E != 1 || param->P != 1 || param->C < 1)
		print_error(1);
	if (!head_init(head))
		print_error(2);
	visited_init(visited, map);
	dfs(visited, param, map, head);
	check_visited(visited);
	return (1);
}