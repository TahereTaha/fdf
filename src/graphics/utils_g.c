/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:00:42 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:56:04 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

int	weighted_abrege(int n0, int n1, float weight)
{
	int		n;
	float	weight0;
	float	weight1;

	weight0 = weight;
	weight1 = 1 - weight;
	n = (int)(weight0 * n0) + (int)(weight1 * n1);
	return (n);
}
