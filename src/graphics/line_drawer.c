/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:33:03 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:53:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

void	draw_line_h(mlx_image_t *img, t_line *line)
{
	float	m;
	int		i;
	int		x;
	int		y;
	int		color;

	if (line->x1 - line->x0 == 0)
		return ;
	m = (float)(line->y1 - line->y0) / (float)(line->x1 - line->x0);
	i = 0;
	while ((line->x0 + i) < line->x1)
	{
		x = line->x0 + i;
		y = line->y0 + (int)(i * m);
		color = get_current_color(line, i);
		if (check_is_in_bounds(x, y))
			mlx_put_pixel(img, x, y, color);
		i++;
	}
}

void	draw_line_v(mlx_image_t *img, t_line *line)
{
	float	m;
	int		i;
	int		x;
	int		y;
	int		color;

	if (line->y1 - line->y0 == 0)
		return ;
	m = (float)(line->x1 - line->x0) / (float)(line->y1 - line->y0);
	i = 0;
	while ((line->y0 + i) < line->y1)
	{
		x = line->x0 + (int)(i * m);
		y = line->y0 + i;
		color = get_current_color(line, i);
		if (check_is_in_bounds(x, y))
			mlx_put_pixel(img, x, y, color);
		i++;
	}
}

void	draw_line(mlx_image_t *img, t_line *line)
{
	int	dx;
	int	dy;

	if ((line->x0 < 0 || line->x0 >= WINDOW_WIDTH
			|| line->y0 < 0 || line->y0 >= WINDOW_HEIGHT)
		&& (line->x1 < 0 || line->x1 >= WINDOW_WIDTH
			|| line->y1 < 0 || line->y1 >= WINDOW_HEIGHT))
		return ;
	fix_line(line);
	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (ft_abs(dx) >= ft_abs(dy))
		draw_line_h(img, line);
	else
		draw_line_v(img, line);
}
