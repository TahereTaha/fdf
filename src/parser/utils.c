/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:29:55 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/25 18:59:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int	ptr_array_size(void	**ptr_array)
{
	int	i;

	i = 0;
	while (ptr_array[i])
		i++;
	return (i);
}

void	do_nothing(void	*foo)
{
	foo += 0;
}

void	**list_to_array(t_list *list)
{
	int		list_size;
	void	**pointer_array;
	t_list	*node;
	int		i;

	list_size = ft_lstsize(list);
	pointer_array = ft_calloc(sizeof(void *), list_size + 1);
	if (!pointer_array)
		return (NULL);
	node = list;
	i = 0;
	while (node)
	{
		pointer_array[i] = node->content;
		i++;
		node = node->next;
	}
	return (pointer_array);
}
