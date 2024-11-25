/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:38:34 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:56:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

t_line	get_2d_line(t_3d_line line_3d)
{
	t_line	line;

	line.x0 = line_3d.point0.x;
	line.x1 = line_3d.point1.x;
	line.y0 = line_3d.point0.y;
	line.y1 = line_3d.point1.y;
	line.color0 = line_3d.color0;
	line.color1 = line_3d.color1;
	return (line);
}
