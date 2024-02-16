/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:27:26 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/16 22:51:16 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc != 2)
		print_error(1);
	param_init(&param, argv[1]);
	set_map(param.map, &param);
	put_img(param.map, &param);
	hook(&param);
	mlx_hook(param.win, PRESS_RED_BUTTON, 0, &end_game, &param);
	mlx_loop(param.mlx);
	return (0);
}

int	end_game(t_param *param)
{
	ft_printf("EARLY END GAME\n");
	ft_printf("Last Moves : %d\n", param->move_cnt);
	exit(1);
	return (0);
}

void	param_init(t_param *param, char *map)
{
	param->map_name = map;
	param->img_w = 0;
	param->img_h = 0;
	param->c = 0;
	param->e = 0;
	param->p = 0;
	param->row = 0;
	param->col = 0;
	param->str = NULL;
	param->x = 0;
	param->y = 0;
	param->move_cnt = 0;
	param->mlx = mlx_init();
	img_init(param);
}

void	*get_xpm_file(char *str, t_param *p)
{
	return (mlx_xpm_file_to_image(p->mlx, str, &p->img_w, &p->img_h));
}
