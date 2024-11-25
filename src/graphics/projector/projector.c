/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:30:37 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 19:00:24 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

//	rotations
t_matrix	m_rotate_z(t_matrix matrix, float angle)
{
	t_matrix	result;
	t_matrix	multiplication_matrix;

	ft_bzero(&multiplication_matrix, sizeof(t_matrix));
	multiplication_matrix.i_hat.x = 1;
	multiplication_matrix.j_hat.y = cosf(angle);
	multiplication_matrix.j_hat.z = sinf(angle);
	multiplication_matrix.k_hat.y = -sinf(angle);
	multiplication_matrix.k_hat.z = cosf(angle);
	result = m_m_multiplication(multiplication_matrix, matrix);
	return (result);
}

t_matrix	m_rotate_y(t_matrix matrix, float angle)
{
	t_matrix	result;
	t_matrix	multiplication_matrix;

	ft_bzero(&multiplication_matrix, sizeof(t_matrix));
	multiplication_matrix.j_hat.y = 1;
	multiplication_matrix.i_hat.x = cosf(angle);
	multiplication_matrix.i_hat.z = -sinf(angle);
	multiplication_matrix.k_hat.x = sinf(angle);
	multiplication_matrix.k_hat.z = cosf(angle);
	result = m_m_multiplication(multiplication_matrix, matrix);
	return (result);
}

//	scale
t_matrix	m_scale(t_matrix basis_vectors, float scale)
{
	basis_vectors.i_hat = v_scaling(basis_vectors.i_hat, scale);
	basis_vectors.j_hat = v_scaling(basis_vectors.j_hat, scale);
	basis_vectors.k_hat = v_scaling(basis_vectors.k_hat, scale);
	return (basis_vectors);
}

//	project
t_matrix	project_unit_vectors(t_prgm_state *prgm_state)
{
	t_matrix	basis_vectors;

	ft_bzero(&basis_vectors, sizeof(t_matrix));
	basis_vectors.i_hat.x = 1;
	basis_vectors.j_hat.y = -1;
	basis_vectors.k_hat.z = -1;
	basis_vectors = m_rotate_y(basis_vectors, prgm_state->yaw);
	basis_vectors = m_rotate_z(basis_vectors, prgm_state->pitch);
	basis_vectors = m_scale(basis_vectors, prgm_state->scale);
	return (basis_vectors);
}

//	this is for the cube only
t_matrix	cube_projection(t_prgm_state *prgm_state)
{
	t_matrix	basis_vectors;

	ft_bzero(&basis_vectors, sizeof(t_matrix));
	basis_vectors.i_hat.x = CUBE_SIZE;
	basis_vectors.j_hat.y = CUBE_SIZE;
	basis_vectors.k_hat.z = CUBE_SIZE;
	basis_vectors = m_rotate_y(basis_vectors, prgm_state->yaw);
	basis_vectors = m_rotate_z(basis_vectors, prgm_state->pitch);
	return (basis_vectors);
}
