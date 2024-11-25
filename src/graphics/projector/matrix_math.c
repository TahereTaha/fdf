/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:36:30 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 19:00:12 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

t_vector	v_addition(t_vector vector0, t_vector vector1)
{
	t_vector	result;

	result.x = vector0.x + vector1.x;
	result.y = vector0.y + vector1.y;
	result.z = vector0.z + vector1.z;
	return (result);
}

t_vector	v_scaling(t_vector vector, float scalar)
{
	t_vector	result;

	result.x = vector.x * scalar;
	result.y = vector.y * scalar;
	result.z = vector.z * scalar;
	return (result);
}

t_vector	v_m_multiplication(t_vector vector, t_matrix matrix)
{
	t_vector	result;
	t_matrix	scaled_basis;

	scaled_basis.i_hat = v_scaling(matrix.i_hat, vector.x);
	scaled_basis.j_hat = v_scaling(matrix.j_hat, vector.y);
	scaled_basis.k_hat = v_scaling(matrix.k_hat, vector.z);
	result = v_addition(scaled_basis.i_hat, scaled_basis.j_hat);
	result = v_addition(result, scaled_basis.k_hat);
	return (result);
}

t_matrix	m_m_multiplication(t_matrix matrix0, t_matrix matrix1)
{
	t_matrix	result;

	result.i_hat = v_m_multiplication(matrix1.i_hat, matrix0);
	result.j_hat = v_m_multiplication(matrix1.j_hat, matrix0);
	result.k_hat = v_m_multiplication(matrix1.k_hat, matrix0);
	return (result);
}
