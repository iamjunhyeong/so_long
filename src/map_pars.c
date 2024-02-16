/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:25:12 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/16 22:51:23 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_map(char *s, char map[], t_param *param)
{
	if (ft_strlen(s) >= 50 || ft_strlen(s) - 1 < 3)
		print_error(1);
	if (param->col != (int)ft_strlen(s) - 1)
		print_error(1);
	while (*s)
	{
		if (*s == '\n' || *s == -1)
			break ;
		if (*s == 'C')
			param->c++;
		else if (*s == 'E')
			param->e++;
		else if (*s == 'P')
			param->p++;
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

void	set_map(char map[][50], t_param *param)
{
	if (ft_strnstr(param->map_name, ".ber", ft_strlen(param->map_name)) == NULL)
		print_error(1);
	param->fd = open(param->map_name, O_RDONLY);
	if (param->fd <= 0)
		print_error(3);
	map_init(map);
	while (1)
	{
		param->str = get_next_line(param->fd);
		if (param->str == NULL)
			break ;
		if (ft_strcmp(param->str, "\n") == 0)
			continue ;
		if (param->col == 0)
			param->col = ft_strlen(param->str) - 1;
		create_map(param->str, map[param->row], param);
		param->row += 1;
		if (param->row >= 50)
			print_error(1);
		free(param->str);
	}
	if (!check_map(map, param) || param->row < 3)
		print_error(1);
	map_size_check(param);
}

void	map_size_check(t_param *p)
{
	p->img_w = p->col * BIT;
	p->img_h = p->row * BIT ;
	p->win = mlx_new_window(p->mlx, p->img_w, p->img_h, "so_long");
}
