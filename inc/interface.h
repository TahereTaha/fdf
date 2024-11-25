/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 06:38:03 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/11 16:45:30 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "MLX42/MLX42.h"

//--------------------------------------------------------------------------//
//	grafics																	//
//--------------------------------------------------------------------------//

void	render_image(mlx_image_t *img, t_prgm_state *prgm_state);

//--------------------------------------------------------------------------//
//	core of the program														//
//--------------------------------------------------------------------------//

//	not able to find a good name
//	int is a structure abstracted from the corre of the program
//	it has all that is needed to manage a window whith mlx
typedef struct s_display
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_display;

typedef struct s_key_hooks_parrams
{
	t_display		*display;
	t_prgm_state	*prgm_state;
}	t_key_hooks_parrams;

void	init_hooks(t_display *display, t_prgm_state *prgm_state);

//	void	prgm_hooks(mlx_key_data_t keydata, void *parram);

void	zoom_hooks(mlx_key_data_t keydata, void *parram);
void	translations_hooks(mlx_key_data_t keydata, void *parram);
void	rotations_hooks(mlx_key_data_t keydata, void *parram);

void	esc_hook(mlx_key_data_t keydata, void *parram);
#endif
