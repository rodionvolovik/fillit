/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:49:01 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 14:24:03 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		*ft_create_elem_coords(int i, int j)
{
	t_coord	*tmp;

	tmp = (t_coord *)malloc(sizeof(t_coord));
	tmp->i = i;
	tmp->j = j;
	tmp->next = NULL;
	return (tmp);
}

void		ft_list_push_coords(t_coord **coord, t_coord *new_m)
{
	t_coord *tmp;

	tmp = *coord;
	if (*coord == NULL)
	{
		*coord = new_m;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_m;
	}
}

t_coord		*find_figure_coords(char **figure)
{
	int		i;
	int		j;
	t_coord	*tmp;

	i = 0;
	tmp = NULL;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (figure[i][j] == BLOCK)
				ft_list_push_coords(&tmp, ft_create_elem_coords(i, j));
			j++;
		}
		i++;
	}
	return (tmp);
}
