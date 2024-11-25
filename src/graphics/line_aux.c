/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:04:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:52 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

void	line_swap_points(t_line *line)
{
	int	temp;

	temp = line->x0;
	line->x0 = line->x1;
	line->x1 = temp;
	temp = line->y0;
	line->y0 = line->y1;
	line->y1 = temp;
	temp = line->color0;
	line->color0 = line->color1;
	line->color1 = temp;
}

void	shorten_line_x(t_line *line)
{
	int		dx;
	int		dy;
	float	m;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	m = (float)dy / (float)dx;
	if (line->x0 < 0)
	{
		line->y0 = line->y0 + (int)(m * (float)-line->x0);
		line->x0 = 0;
	}
	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (line->x1 >= WINDOW_WIDTH)
	{
		line->y1 = line->y0 + (int)(m * (WINDOW_WIDTH - line->x0));
		line->x1 = WINDOW_WIDTH - 1;
	}
}

void	shorten_line_y(t_line *line)
{
	int		dx;
	int		dy;
	float	m;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	m = (float)dx / (float)dy;
	if (line->y0 < 0)
	{
		line->x0 = line->x0 + (int)(m * (float)-line->y0);
		line->y0 = 0;
	}
	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (line->y1 >= WINDOW_HEIGHT)
	{
		line->x1 = line->x0 + (int)(m * (float)(WINDOW_HEIGHT - line->y0));
		line->y1 = WINDOW_HEIGHT - 1;
	}
}

void	shorten_line(t_line *line)
{
	shorten_line_x(line);
	shorten_line_y(line);
}

void	fix_line(t_line *line)
{
	int	dx;
	int	dy;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (ft_abs(dx) >= ft_abs(dy) && line->x0 > line->x1)
		line_swap_points(line);
	if (ft_abs(dx) < ft_abs(dy) && line->y0 > line->y1)
		line_swap_points(line);
	shorten_line(line);
}
