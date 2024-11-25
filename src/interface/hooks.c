/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:19:28 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:58:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"
#include "interface.h"
#include "MLX42/MLX42.h"

static void	key_hooks(mlx_key_data_t keydata, void *parrams)
{
	t_key_hooks_parrams	*hooks_parrams;
	static t_display	*display;
	static t_prgm_state	*prgm_state;

	hooks_parrams = (t_key_hooks_parrams *)parrams;
	display = hooks_parrams->display;
	prgm_state = hooks_parrams->prgm_state;
	zoom_hooks(keydata, prgm_state);
	translations_hooks(keydata, prgm_state);
	rotations_hooks(keydata, prgm_state);
	esc_hook(keydata, display);
}

void	init_hooks(t_display *display, t_prgm_state *prgm_state)
{
	static t_key_hooks_parrams	key_hooks_parrams;

	key_hooks_parrams.display = display;
	key_hooks_parrams.prgm_state = prgm_state;
	mlx_key_hook(display->mlx, &key_hooks, &key_hooks_parrams);
}
