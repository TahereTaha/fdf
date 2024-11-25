/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 05:35:54 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:56 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "interface.h"
#include "graphics.h"
#include "MLX42/MLX42.h"

void	render_image(mlx_image_t *img, t_prgm_state *prgm_state)
{
	draw_cube(img, prgm_state);
	draw_map(img, prgm_state);
}

//	the main one
/*
void	render_image(mlx_image_t *img, t_prgm_state *prgm_state)
{
	t_line	line;

	(void )img;
	(void ) prgm_state;
	line.color0 = 0xff0000ff;
	line.color1 = 0x00ff00ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 100;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 10;
	draw_line(img, &line);
}
*/
/*
//	test colors


void	render_image(mlx_image_t *img, t_prgm_state *prgm_state)
{
	(void )img;
	(void ) prgm_state;
	t_line line;

	line.color0 = 0x123456ff;
	line.color1 = 0x012345ff;

	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 50;

	draw_line(img, &line);
}

*/

/*
//	test of the lines

void	render_image(mlx_image_t *img, t_prgm_state *prgm_state)
{
	(void )img;
	(void ) prgm_state;
	t_line line;

	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;

//
//	the 16 lines that my program shoud suport/

//	the 3:00
	
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2;

	draw_line(img, &line);

//	the 3:45
	
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 100;

	draw_line(img, &line);

//	the 4:30
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 200;

	draw_line(img, &line);

//	the 5:15
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 100;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 200;

	draw_line(img, &line);

//	the 6:00
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 200;

	draw_line(img, &line);

//	the 6:45
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 100;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 200;

	draw_line(img, &line);

//	the 7:30
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 200;

	draw_line(img, &line);

//	the 8:45
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 + 100;

	draw_line(img, &line);

//	the 9:00
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 9:00\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2;

	draw_line(img, &line);

//	the 9:45
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 9:45\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 100;

	draw_line(img, &line);

//	the 10:30
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 10:30\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 200;

	draw_line(img, &line);

//	the 11:15
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 11:15\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 - 100;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 200;

	draw_line(img, &line);

//	the 12:00
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 12:00\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 200;

	draw_line(img, &line);

//	the 0:45
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 0:45\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 100;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 200;

	draw_line(img, &line);

//	the 1:30
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 1:30\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 200;

	draw_line(img, &line);

//	the 2:45
	line.color0 = 0xffffffff;
	line.color1 = 0x555555ff;
	printf("the line represents a clock at 2:45\n");
	line.x0 = WINDOW_WIDTH / 2;
	line.x1 = WINDOW_WIDTH / 2 + 200;
	line.y0 = WINDOW_HEIGHT / 2;
	line.y1 = WINDOW_HEIGHT / 2 - 100;

	draw_line(img, &line);

//	the second quadrant slope < 1
//	the second quadrant slope < 1

	return ;
}
*/
