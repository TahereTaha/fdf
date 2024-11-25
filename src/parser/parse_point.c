/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:46:26 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:59:30 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static int	fast_atoi_hex(char *str)
{
	int	color;
	int	digit;

	color = 0;
	while (*str)
	{
		digit = ft_strchr(HEX_BASE, *str) - HEX_BASE;
		color <<= 4;
		color |= digit;
		str++;
	}
	color <<= 8;
	color |= 0xff;
	return (color);
}

//	the hex_color has the prefix of ,0x
static int	read_hex_color(char *hex_color)
{
	int	color;

	color = 0xffffffff;
	if (hex_color[0] != ',' || hex_color[1] != '0' || hex_color[2] != 'x')
		return (color);
	color = 0x0;
	hex_color += 3;
	color = fast_atoi_hex(hex_color);
	return (color);
}

static char	*get_color_str(char *point_str)
{
	if (*point_str == '-')
		point_str++;
	while (ft_isdigit(*point_str))
		point_str++;
	return (point_str);
}

t_point	*parse_point(char *point_str)
{
	t_point	*point;
	char	*color_str;

	point = calloc(sizeof(t_point), 1);
	if (!point)
		return (NULL);
	point->height = ft_atoi(point_str);
	color_str = get_color_str(point_str);
	point->color = read_hex_color(color_str);
	return (point);
}
