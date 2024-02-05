/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:27:26 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/05 22:37:45 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*img;
	void	*mlx;
	// void	*mlx_ptr;
	// void	*win_ptr;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	// mlx_loop(mlx_ptr); 
}
