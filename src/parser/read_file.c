/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:44:49 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 19:05:36 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

//	get a map of the strings for the ponits
int	strs_width(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static void	free_strs(void *strs_p)
{
	char	**strs;
	int		i;

	strs = strs_p;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_str_map(char ***str_map)
{
	int	i;

	i = 0;
	while (str_map[i])
	{
		free_strs(str_map[i]);
		i++;
	}
	free(str_map);
}

static char	**get_point_line(int fd, int width)
{
	char	*line;
	char	*tmp_line;
	char	**point_list;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	tmp_line = ft_strtrim(line, " \n");
	free(line);
	line = tmp_line;
	point_list = ft_split(line, ' ');
	free(line);
	if (!point_list)
		return (NULL);
	if (width != -1 && width != strs_width(point_list))
	{
		free_strs(point_list);
		return ((char **)-1);
	}
	return (point_list);
}

char	***get_str_point_map(int fd)
{
	t_list	*lines_list;
	char	**line;
	char	***map;
	int		line_width;

	lines_list = NULL;
	line = get_point_line(fd, -1);
	line_width = strs_width(line);
	while (line)
	{
		ft_lstadd_back(&lines_list, ft_lstnew(line));
		line = get_point_line(fd, line_width);
		if (line == (char **)-1)
		{
			ft_lstclear(&lines_list, &free_strs);
			return (NULL);
		}
	}
	map = (char ***)list_to_array(lines_list);
	ft_lstclear(&lines_list, &do_nothing);
	return (map);
}
