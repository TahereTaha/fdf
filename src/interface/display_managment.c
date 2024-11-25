/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:29:07 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 19:06:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "MLX42/MLX42.h"

void	loop_gui(t_gui gui)
{
	t_display	*display;

	display = gui;
	mlx_loop(display->mlx);
	mlx_close_window(display->mlx);
	close_gui(gui);
}

void	update_gui(t_gui gui, t_prgm_state *prgm_state)
{
	static t_display	*display;
	mlx_image_t			*new_img;

	if (gui)
		display = gui;
	new_img = mlx_new_image(display->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!new_img)
		exit(1);
	render_image(new_img, prgm_state);
	if (mlx_image_to_window(display->mlx, new_img, 0, 0) < 0)
		exit(1);
	if (display->img)
		mlx_delete_image(display->mlx, display->img);
	display->img = new_img;
	ft_putstr_fd("\nthe display has ben updated\n\n", 1);
}

void	close_gui(t_gui gui)
{
	t_display	*display;

	display = gui;
	mlx_delete_image(display->mlx, display->img);
	mlx_terminate(display->mlx);
}
