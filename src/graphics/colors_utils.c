/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:29:43 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:43 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

int	get_chanel(int color, t_chanel chanel)
{
	int	chanel_value;

	if (chanel == RED)
	{
		chanel_value = (color >> 24) & 0xff;
		return (chanel_value);
	}
	else if (chanel == GREAN)
	{
		chanel_value = (color >> 16) & 0xff;
		return (chanel_value);
	}
	else if (chanel == BLUE)
	{
		chanel_value = (color >> 8) & 0xff;
		return (chanel_value);
	}
	return (0);
}

float	get_line_progresion(t_line *line, int i)
{
	int		dx;
	int		dy;
	int		dmax;
	float	weight;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	dmax = ft_abs(dx);
	if (dmax < ft_abs(dy))
		dmax = ft_abs(dy);
	weight = (float)i / (float)dmax;
	return (weight);
}

int	get_current_color(t_line *line, int i)
{
	float	weight;
	int		color_old;
	int		color_future;
	int		color_current;

	weight = get_line_progresion(line, i);
	color_current = 0;
	color_old = get_chanel(line->color0, RED);
	color_future = get_chanel(line->color1, RED);
	color_current |= weighted_abrege(color_future, color_old, weight) << 24;
	color_old = get_chanel(line->color0, GREAN);
	color_future = get_chanel(line->color1, GREAN);
	color_current |= weighted_abrege(color_future, color_old, weight) << 16;
	color_old = get_chanel(line->color0, BLUE);
	color_future = get_chanel(line->color1, BLUE);
	color_current |= weighted_abrege(color_future, color_old, weight) << 8;
	color_current |= 0xff;
	return (color_current);
}
