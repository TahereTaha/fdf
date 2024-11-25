/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:44:05 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/16 12:21:22 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_prgm_state(t_prgm_state *prgm_state)
{
	prgm_state->yaw = STARTING_YAW;
	prgm_state->pitch = STARTING_PITCH;
	prgm_state->scale = STARTING_SCALE;
	prgm_state->z_scale = STARTING_Z_SCALE;
	prgm_state->x = 0;
	prgm_state->y = 0;
}
