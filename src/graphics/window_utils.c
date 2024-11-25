/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:35:21 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:56:13 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

int	check_is_in_bounds(int x, int y)
{
	if (x < 0 || x >= WINDOW_WIDTH)
		return (0);
	if (y < 0 || y >= WINDOW_HEIGHT)
		return (0);
	return (1);
}
/*
int	current_collor(t_line *line, int i)
{
	int	chanel_old;
	int	chanel_future;
	int	chanel_current;
	int	color;

	chanel_old = clolar0 >> 24;
	chanel_future = clolar0 >> 24;
	chanel_current = weighted_abrege(line, i, RED);
}
*/
