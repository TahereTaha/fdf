/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_control_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:24:40 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/17 05:53:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "MLX42/MLX42.h"

void	zoom_hooks(mlx_key_data_t keydata, void *parram)
{
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		prgm_state_zoom_in(parram);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		prgm_state_zoom_out(parram);
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		prgm_state_z_zoom_in(parram);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
		prgm_state_z_zoom_out(parram);
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_REPEAT)
		prgm_state_zoom_in(parram);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_REPEAT)
		prgm_state_zoom_out(parram);
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_REPEAT)
		prgm_state_z_zoom_in(parram);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_REPEAT)
		prgm_state_z_zoom_out(parram);
}

void	translations_hooks(mlx_key_data_t keydata, void *parram)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		prgm_state_translate_left(parram);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		prgm_state_translate_up(parram);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		prgm_state_translate_down(parram);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		prgm_state_translate_right(parram);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		prgm_state_translate_left(parram);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		prgm_state_translate_up(parram);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		prgm_state_translate_down(parram);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		prgm_state_translate_right(parram);
}

void	rotations_hooks(mlx_key_data_t keydata, void *parram)
{
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		prgm_state_rotate_right(parram);
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		prgm_state_rotate_left(parram);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		prgm_state_rotate_up(parram);
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		prgm_state_rotate_down(parram);
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_REPEAT)
		prgm_state_rotate_right(parram);
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_REPEAT)
		prgm_state_rotate_left(parram);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_REPEAT)
		prgm_state_rotate_up(parram);
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_REPEAT)
		prgm_state_rotate_down(parram);
}
