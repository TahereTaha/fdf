/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:09:54 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 13:41:24 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

typedef enum e_chanel
{
	RED,
	GREAN,
	BLUE,
}	t_chanel;

typedef struct s_point_3d
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point_3d;

//	this is in relation to the 
typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color0;
	int	color1;
}	t_line;

void		draw_line(mlx_image_t *img, t_line *line);

void		line_swap_points(t_line *line);
void		fix_line(t_line *line);
int			check_is_in_bounds(int x, int y);
int			get_current_color(t_line *line, int i);
int			weighted_abrege(int n0, int n1, float weight);

typedef enum e_cordinates
{
	X,
	Y,
	Z,
}	t_cordinates;

typedef enum e_basis_v
{
	I_HAT,
	J_HAT,
	K_HAT,
}	t_basis_v;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_matrix
{
	t_vector	i_hat;
	t_vector	j_hat;
	t_vector	k_hat;
}	t_matrix;

typedef struct s_3d_line
{
	t_vector	point0;
	t_vector	point1;
	int			color0;
	int			color1;
}	t_3d_line;

t_vector	v_addition(t_vector vector0, t_vector vector1);
t_vector	v_scaling(t_vector vector, float scalar);
t_vector	v_m_multiplication(t_vector vector, t_matrix matrix);
t_matrix	m_m_multiplication(t_matrix matrix0, t_matrix matrix1);

t_matrix	project_unit_vectors(t_prgm_state *prgm_state);
t_matrix	cube_projection(t_prgm_state *prgm_state);

t_line		get_2d_line(t_3d_line line_3d);

void		draw_cube(mlx_image_t *img, t_prgm_state *prgm_state);
void		draw_map(mlx_image_t *img, t_prgm_state *prgm_state);

t_line		get_line(t_3d_line line_3d, t_matrix mtrx);
t_3d_line	get_line_3d_h(t_prgm_state *prgm_state, int i, int j);
t_3d_line	get_line_3d_v(t_prgm_state *prgm_state, int i, int j);

# define CUBE_SIZE 50
# define CUBE_X 100
# define CUBE_Y 100

#endif
