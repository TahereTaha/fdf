/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:28 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/09 16:45:05 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "MLX42/MLX42.h"

t_display	*init_display(void)
{
	static t_display	display[1];
	mlx_t				*mlx;
	mlx_image_t			*img;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "fdf", false);
	if (!mlx)
		exit(1);
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img)
		exit(1);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(1);
	display->mlx = mlx;
	display->img = img;
	return (display);
}

t_gui	init_gui(t_prgm_state *prgm_state)
{
	t_display	*display;

	display = init_display();
	init_hooks(display, prgm_state);
	return (display);
}
