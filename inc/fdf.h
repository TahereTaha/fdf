/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 06:17:21 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 13:47:15 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_point
{
	int	height;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	***points;
	int		width;
	int		length;
	int		max_point;
	int		min_point;
}	t_map;

typedef struct s_program_state
{
	t_map	*map;
	float	yaw;
	float	pitch;
	float	row;
	float	scale;
	float	z_scale;
	float	x;
	float	y;
}	t_prgm_state;

//--------------------------------------------------------------------------//
//	parsing																	//
//--------------------------------------------------------------------------//

t_map	*parse_file(char *file);

//--------------------------------------------------------------------------//
//	interface																//
//--------------------------------------------------------------------------//

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024

typedef void	*t_gui;

t_gui	init_gui(t_prgm_state *prgm_state);
void	loop_gui(t_gui gui);
void	update_gui(t_gui gui, t_prgm_state *prgm_state);
void	close_gui(t_gui gui);

//--------------------------------------------------------------------------//
//	core of the program														//
//--------------------------------------------------------------------------//

void	print_state(t_prgm_state *prgm_state);

# define FULL_ROTATION 6.2832
# define STARTING_YAW 0.7854
# define STARTING_PITCH 0.6155
# define STARTING_SCALE 50
# define STARTING_Z_SCALE 0.08

void	init_prgm_state(t_prgm_state *prgm_state);

# define ZOOM_STEP	1
# define Z_ZOOM_STEP 0.01

void	prgm_state_zoom_in(t_prgm_state *prgm_state);
void	prgm_state_zoom_out(t_prgm_state *prgm_state);
void	prgm_state_z_zoom_in(t_prgm_state *prgm_state);
void	prgm_state_z_zoom_out(t_prgm_state *prgm_state);

//	the norminete is stupit this shoud of ben 
//	FULL_ROTATION / 360
# define ROTATION_ANGLE 0.017453

void	prgm_state_rotate_right(t_prgm_state *prgm_state);
void	prgm_state_rotate_left(t_prgm_state *prgm_state);
void	prgm_state_rotate_up(t_prgm_state *prgm_state);
void	prgm_state_rotate_down(t_prgm_state *prgm_state);

# define TRANSLATION_DISTANCE 0.25

void	prgm_state_translate_right(t_prgm_state *prgm_state);
void	prgm_state_translate_left(t_prgm_state *prgm_state);
void	prgm_state_translate_up(t_prgm_state *prgm_state);
void	prgm_state_translate_down(t_prgm_state *prgm_state);

#endif

//
//
//
//
//
//
/*
the core of the program
	+ (done) make my program print to terminal the current program state
	+ (done) fix the make file
	+ (doen) get the vasic functions
	for manipulating the value of the program state
the display of the program
	+ (done) make a window
	+ (done) get user input (nearyl, the only thing mising is the esc key)
	+ (done) do rigth the window managment
integrate the parsing to the project
	+ (done) fix the error handeling of the parsing
	+ (done) get the parsing on the main.c
grafics
	+ (done) draw a line
	+ (done) draw the same line with colors
projector
	+ (done) make the diferent auxiliar function for matrix multiplication
	+ (done) make the units of the 3d space
	+ (done) make the units rotate
	+ (done) project the units
	+ (done) translate them
drawing
	+ (done) draw a cube
	+ (done) draw the map
polishing
	+ (done) fix map orientation
	+ (done) fix map height (add height control)
	+ (done) fix hard to see color
	+ (done) fix colors
features aditional
	+ (done) add the orientation cube
last fixes for sending it to correction
	+ (done) implement a beter line algorithm
	+ (done) pass norminet
	- get colors on default projections
	- get some default projectinons
*/
