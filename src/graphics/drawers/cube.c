/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:28:29 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:56:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

const static t_3d_line	g_cube_lines[12] = \
	{\
	{{1, 1, 1}, {1, 1, -1}, 0xffffffff, 0xffffffff}, \
	{{1, -1, 1}, {1, -1, -1}, 0xffffffff, 0xffffffff}, \
	{{1, 1, 1}, {1, -1, 1}, 0xffffffff, 0xffffffff}, \
	{{1, 1, -1}, {1, -1, -1}, 0xffffffff, 0xffffffff}, \
\
	{{-1, 1, 1}, {-1, 1, -1}, 0x00ff00ff, 0xffffffff}, \
	{{-1, -1, 1}, {-1, -1, -1}, 0xffffffff, 0xffffffff}, \
	{{-1, 1, 1}, {-1, -1, 1}, 0x0000ffff, 0xffffffff}, \
	{{-1, 1, -1}, {-1, -1, -1}, 0xffffffff, 0xffffffff}, \
\
	{{1, 1, 1}, {-1, 1, 1}, 0xffffffff, 0xff0000ff}, \
	{{1, 1, -1}, {-1, 1, -1}, 0xffffffff, 0xffffffff}, \
	{{1, -1, 1}, {-1, -1, 1}, 0xffffffff, 0xffffffff}, \
	{{1, -1, -1}, {-1, -1, -1}, 0xffffffff, 0xffffffff}, \
};

void	draw_cube(mlx_image_t *img, t_prgm_state *prgm_state)
{
	t_line		line;
	t_3d_line	line_3d;
	t_matrix	matrix;
	int			i;

	matrix = cube_projection(prgm_state);
	i = 0;
	while (i < 12)
	{
		line_3d = g_cube_lines[i];
		line_3d.point0 = v_m_multiplication(line_3d.point0, matrix);
		line_3d.point1 = v_m_multiplication(line_3d.point1, matrix);
		line_3d.point0.x += CUBE_X;
		line_3d.point1.x += CUBE_X;
		line_3d.point0.y += CUBE_Y;
		line_3d.point1.y += CUBE_Y;
		line = get_2d_line(line_3d);
		draw_line(img, &line);
		i++;
	}
}
