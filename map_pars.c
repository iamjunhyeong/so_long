/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:25:12 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/13 21:30:17 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int type)
{
	if (type == 1)
		ft_printf("Error\n");
	else if (type == 2)
		ft_printf("malloc Error\n");
	exit(1);
}

void	create_map(char *s, char map[], t_param *param)
{
	if (ft_strlen(s) >= 50)
		print_error(1);
	if (param->col != 0 && param->col != (int)ft_strlen(s))
		print_error(1);
	while (*s)
	{
		if (*s == '\n' || *s == -1)
			break ;
		if (*s == 'C')
			param->C++;
		else if (*s == 'E')
			param->E++;
		else if (*s == 'P')
			param->P++;
		else if (*s != '0' && *s != '1')
			print_error(1);
		*map++ = *s++;
	}
}

void	map_init(char map[][50])
{
	int	i;
	int	j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			map[i][j] = -1;
			j++;
		}
		i++;
	}
}

void set_map(char map[][50], t_param *param)
{
	map_init(map);
	param->fd = open("map1.ber", O_RDONLY);
	while (1)
	{
		param->str = get_next_line(param->fd);
		if (param->str == NULL)
			break ;
		create_map(param->str, map[param->row], param);
		param->row += 1;
		if (param->row >= 50)
			print_error(1);
		free(param->str);
	}
	find_player(param, param->map);
	find_portal(param, param->map);
	if (!check_map(map, param)) 	// wall check, p check, etc..
		print_error(1);
}
