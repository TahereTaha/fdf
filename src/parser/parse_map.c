/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:44:26 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:59:17 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static void	free_point_row(t_point **row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		free(row[i]);
		i++;
	}
	free(row);
}

void	free_point_map(t_point ***map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free_point_row(map[i]);
		i++;
	}
	free(map);
}

static t_point	**parse_str_point_row(char **str_row)
{
	int		width;
	int		i;
	t_point	**point_row;

	width = ptr_array_size((void **)str_row);
	point_row = calloc(sizeof(t_point *), width + 1);
	if (!point_row)
		return (NULL);
	i = 0;
	while (str_row[i])
	{
		point_row[i] = parse_point(str_row[i]);
		if (!point_row[i])
		{
			free_point_row(point_row);
			return (NULL);
		}
		i++;
	}
	return (point_row);
}

t_point	***parse_str_point_map(char ***str_map)
{
	int		height;
	int		i;
	t_point	***point_map;

	height = ptr_array_size((void **)str_map);
	point_map = calloc(sizeof(t_point *), height + 1);
	if (!point_map)
		return (NULL);
	i = 0;
	while (str_map[i])
	{
		point_map[i] = parse_str_point_row(str_map[i]);
		if (!point_map[i])
		{
			free_point_map(point_map);
			return (NULL);
		}
		i++;
	}
	return (point_map);
}
