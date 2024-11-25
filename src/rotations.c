/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:59:51 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/16 10:39:34 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	prgm_state_rotate_right(t_prgm_state *prgm_state)
{
	ft_putstr_fd("rotating to the right\n", 1);
	prgm_state->yaw += ROTATION_ANGLE;
	if (prgm_state->yaw > FULL_ROTATION)
		prgm_state->yaw -= FULL_ROTATION;
	update_gui(NULL, prgm_state);
}

void	prgm_state_rotate_left(t_prgm_state *prgm_state)
{
	ft_putstr_fd("rotating to the left\n", 1);
	prgm_state->yaw -= ROTATION_ANGLE;
	if (prgm_state->yaw < 0)
		prgm_state->yaw += FULL_ROTATION;
	update_gui(NULL, prgm_state);
}

//	the rotations on the pitch will be limited in a small range
//	this makes so that the mesh cant be seen from bellow.
//	it is only estetic this limit.
void	prgm_state_rotate_up(t_prgm_state *prgm_state)
{
	ft_putstr_fd("rotating to the up\n", 1);
	prgm_state->pitch += ROTATION_ANGLE;
	if (prgm_state->pitch < 0)
		prgm_state->pitch -= FULL_ROTATION;
	update_gui(NULL, prgm_state);
}

void	prgm_state_rotate_down(t_prgm_state *prgm_state)
{
	ft_putstr_fd("rotating to the down\n", 1);
	prgm_state->pitch -= ROTATION_ANGLE;
	if (prgm_state->pitch < 0)
		prgm_state->pitch += FULL_ROTATION;
	update_gui(NULL, prgm_state);
}
