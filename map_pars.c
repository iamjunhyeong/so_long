/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:25:12 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/12 21:29:04 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int type)
{
	if (type == 1)
		write(1, "Error\n", 6);
	exit(1);
}

void	create_map(char *s, char map[], t_mapinfo *mi)
{
	if (ft_strlen(s) >= 50)
		print_error(1);
	if (mi->col != 0 && mi->col != (int)ft_strlen(s))
		print_error(1);
	while (*s)
	{
		if (*s == '\n')
			break ;
		if (*s == 'C')
			mi->C++;
		else if (*s == 'E')
			mi->E++;
		else if (*s == 'P')
			mi->P++;
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
	j = 0;
	while (i < 50)
	{
		while (j < 50)
		{
			map[i][j] = -1;
			j++;
		}
		i++;
	}
}

int	check_map(char map[][50])
{
	if (map)
		return (1);
	return (1);
}

void set_map(char map[][50])
{
	t_mapinfo	mi;

	map_init(map);
	mi = (struct s_mapinfo){NULL, 0, 0, 0, 0, 0, 0};
	mi.fd = open("map1.ber", O_RDONLY);
	while (1)
	{
		mi.str = get_next_line(mi.fd);
		if (mi.str == NULL)
			break ;
		create_map(mi.str, map[mi.row], &mi);
		mi.row++;
		if (mi.row >= 50)
			print_error(1);
		free(mi.str);
	}
	if (!check_map(map))
		print_error(1);
}
