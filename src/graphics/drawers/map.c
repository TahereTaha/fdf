/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 06:47:25 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 13:43:06 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

void	draw_map_h(mlx_image_t *img, t_prgm_state *prgm_state, t_matrix mtrx)
{
	int			i;
	int			j;
	t_3d_line	line_3d;
	t_line		line;

	j = 0;
	while (j < prgm_state->map->length)
	{
		i = 0;
		while ((i + 1) < prgm_state->map->width)
		{
			line_3d = get_line_3d_h(prgm_state, i, j);
			line = get_line(line_3d, mtrx);
			draw_line(img, &line);
			i++;
		}
		j++;
	}
}

void	draw_map_v(mlx_image_t *img, t_prgm_state *prgm_state, t_matrix mtrx)
{
	int			i;
	int			j;
	t_3d_line	line_3d;
	t_line		line;

	j = 0;
	while ((j + 1) < prgm_state->map->length)
	{
		i = 0;
		while (i < prgm_state->map->width)
		{
			line_3d = get_line_3d_v(prgm_state, i, j);
			line = get_line(line_3d, mtrx);
			draw_line(img, &line);
			i++;
		}
		j++;
	}
}

void	draw_map(mlx_image_t *img, t_prgm_state *prgm_state)
{
	t_matrix	mtrx;

	mtrx = project_unit_vectors(prgm_state);
	draw_map_h(img, prgm_state, mtrx);
	draw_map_v(img, prgm_state, mtrx);
}
