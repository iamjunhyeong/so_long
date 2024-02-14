/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:09:35 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/13 22:03:26 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_portal(t_param *param, char map[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50 && map[i][j] != 'E')
			j++;
		if (map[i][j] == 'E')
			break ;
		i++;
	}
	param->ex = i;
	param->ey = j;
}

void	find_player(t_param *param, char map[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50 && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	param->x = i;
	param->y = j;
}

void	visited_init(char visited[][50], char map[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			if (map[i][j] != '0')
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_head	*head_init()
{
	t_head	*tmp;

	tmp = (t_head *)malloc(sizeof(t_head));
	if (!tmp)
		return (NULL);
	tmp->size = 0;
	tmp->top = NULL;
	return (tmp);
}