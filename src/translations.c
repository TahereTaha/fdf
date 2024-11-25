/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:37:01 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/06 07:11:45 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	prgm_state_translate_right(t_prgm_state *prgm_state)
{
	ft_putstr_fd("translating to the right\n", 1);
	prgm_state->x += TRANSLATION_DISTANCE;
	update_gui(NULL, prgm_state);
}

void	prgm_state_translate_left(t_prgm_state *prgm_state)
{
	ft_putstr_fd("translating to the left\n", 1);
	prgm_state->x -= TRANSLATION_DISTANCE;
	update_gui(NULL, prgm_state);
}

void	prgm_state_translate_up(t_prgm_state *prgm_state)
{
	ft_putstr_fd("translating to the up\n", 1);
	prgm_state->y += TRANSLATION_DISTANCE;
	update_gui(NULL, prgm_state);
}

void	prgm_state_translate_down(t_prgm_state *prgm_state)
{
	ft_putstr_fd("translating to the down\n", 1);
	prgm_state->y -= TRANSLATION_DISTANCE;
	update_gui(NULL, prgm_state);
}
