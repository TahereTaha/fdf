/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 06:51:20 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/04 09:21:06 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fdf.h"

// the correct one 
# define BUFFER_SIZE 32768

# define HEX_BASE "0123456789abcdef"

//	some utils functions

void	**list_to_array(t_list *list);
int		ptr_array_size(void	**ptr_array);
void	do_nothing(void	*foo);

//	the important functions on this code section

char	***get_str_point_map(int fd);
void	free_str_map(char ***str_map);

t_point	*parse_point(char *point_str);

void	free_point_map(t_point ***map);
t_point	***parse_str_point_map(char ***str_map);

#endif
