/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:37:35 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/16 12:42:20 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	prgm_state_zoom_in(t_prgm_state *prgm_state)
{
	ft_putstr_fd("zooming in\n", 1);
	prgm_state->scale += ZOOM_STEP;
	update_gui(NULL, prgm_state);
}

void	prgm_state_zoom_out(t_prgm_state *prgm_state)
{
	ft_putstr_fd("zooming out\n", 1);
	if (prgm_state->scale <= ZOOM_STEP)
	{
		ft_putstr_fd("unable to make more zoom out\n", 1);
		return ;
	}
	prgm_state->scale -= ZOOM_STEP;
	update_gui(NULL, prgm_state);
}

void	prgm_state_z_zoom_in(t_prgm_state *prgm_state)
{
	ft_putstr_fd("z zooming in\n", 1);
	prgm_state->z_scale += Z_ZOOM_STEP;
	update_gui(NULL, prgm_state);
}

void	prgm_state_z_zoom_out(t_prgm_state *prgm_state)
{
	ft_putstr_fd("z zooming out\n", 1);
	if (prgm_state->z_scale <= Z_ZOOM_STEP)
	{
		ft_putstr_fd("unable to make more z zoom out\n", 1);
		return ;
	}
	prgm_state->z_scale -= Z_ZOOM_STEP;
	update_gui(NULL, prgm_state);
}
