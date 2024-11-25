/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 06:58:53 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/12 06:11:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static int	file_is_valid(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("the amount of arrguments is incorect\n", 2);
		return (0);
	}
	if (ft_strncmp(".fdf", &(av[1][ft_strlen(av[1]) - 4]), 5))
	{
		ft_putstr_fd("the file extension is incorrect\n", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	static t_prgm_state	prgm_state;
	t_gui				gui;

	if (!file_is_valid(ac, av))
		return (1);
	init_prgm_state(&prgm_state);
	gui = init_gui(&prgm_state);
	prgm_state.map = parse_file(av[1]);
	if (!prgm_state.map)
	{
		ft_putstr_fd("unable to read the file\n", 2);
		close_gui(gui);
		return (1);
	}
	update_gui(gui, &prgm_state);
	loop_gui(gui);
	return (0);
}
