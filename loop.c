/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:55:36 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/12 21:26:50 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>


int render_next_frame(void *YourStruct);

int main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_loop_hook(mlx, render_next_frame, YourStruct);
	mlx_loop(mlx);
}