/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:27:24 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:58:34 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"
#include "interface.h"
#include "MLX42/MLX42.h"

void	esc_hook(mlx_key_data_t keydata, void *parram)
{
	if (keydata.key != MLX_KEY_ESCAPE || keydata.action != MLX_PRESS)
		return ;
	ft_putstr_fd("closing the program\n", 1);
	close_gui(parram);
	exit(0);
}
