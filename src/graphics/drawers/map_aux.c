/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 05:57:23 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 13:48:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

t_line	get_line(t_3d_line line_3d, t_matrix mtrx)
{
	t_line	line;
	int		middle_x;
	int		middle_y;

	middle_x = WINDOW_WIDTH / 2;
	middle_y = WINDOW_HEIGHT / 2;
	line_3d.point0 = v_m_multiplication(line_3d.point0, mtrx);
	line_3d.point1 = v_m_multiplication(line_3d.point1, mtrx);
	line_3d.point0.x += middle_x;
	line_3d.point1.x += middle_x;
	line_3d.point0.y += middle_y;
	line_3d.point1.y += middle_y;
	line = get_2d_line(line_3d);
	return (line);
}

t_3d_line	get_line_3d_h(t_prgm_state *prgm_state, int i, int j)
{
	t_3d_line	line_3d;
	float		z_scale;

	z_scale = prgm_state->z_scale;
	line_3d.point0.x = i - (prgm_state->map->width / 2) + prgm_state->x;
	line_3d.point0.z = j - (prgm_state->map->length / 2) - prgm_state->y;
	line_3d.point0.y = prgm_state->map->points[j][i]->height * z_scale;
	line_3d.color0 = prgm_state->map->points[j][i]->color;
	i++;
	line_3d.point1.x = i - (prgm_state->map->width / 2) + prgm_state->x;
	line_3d.point1.z = j - (prgm_state->map->length / 2) - prgm_state->y;
	line_3d.point1.y = prgm_state->map->points[j][i]->height * z_scale;
	line_3d.color1 = prgm_state->map->points[j][i]->color;
	return (line_3d);
}

t_3d_line	get_line_3d_v(t_prgm_state *prgm_state, int i, int j)
{
	t_3d_line	line_3d;
	float		z_scale;

	z_scale = prgm_state->z_scale;
	line_3d.point0.x = i - (prgm_state->map->width / 2) + prgm_state->x;
	line_3d.point0.z = j - (prgm_state->map->length / 2) - prgm_state->y;
	line_3d.point0.y = prgm_state->map->points[j][i]->height * z_scale;
	line_3d.color0 = prgm_state->map->points[j][i]->color;
	j++;
	line_3d.point1.x = i - (prgm_state->map->width / 2) + prgm_state->x;
	line_3d.point1.z = j - (prgm_state->map->length / 2) - prgm_state->y;
	line_3d.point1.y = prgm_state->map->points[j][i]->height * z_scale ;
	line_3d.color1 = prgm_state->map->points[j][i]->color;
	return (line_3d);
}
