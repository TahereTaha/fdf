/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:11:39 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:59:03 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int	max_point_in_map(t_point ***map)
{
	int	i;
	int	j;
	int	max;

	max = (**map)->height;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->height > max)
				max = map[i][j]->height;
			j++;
		}
		i++;
	}
	return (max);
}

int	min_point_in_map(t_point ***map)
{
	int	i;
	int	j;
	int	min;

	min = (**map)->height;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->height < min)
				min = map[i][j]->height;
			j++;
		}
		i++;
	}
	return (min);
}

void	set_map_data(t_map *map, t_point ***point_map)
{
	map->points = point_map;
	map->width = ptr_array_size((void **)*point_map);
	map->length = ptr_array_size((void **)point_map);
	map->max_point = max_point_in_map(point_map);
	map->min_point = min_point_in_map(point_map);
}

t_map	*parse_file(char *file_name)
{
	int		fd;
	char	***str_map;
	t_point	***point_map;
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str_map = get_str_point_map(fd);
	close(fd);
	if (!str_map)
	{
		free(map);
		return (NULL);
	}
	point_map = parse_str_point_map(str_map);
	free_str_map(str_map);
	if (!point_map)
		return (NULL);
	set_map_data(map, point_map);
	return (map);
}
