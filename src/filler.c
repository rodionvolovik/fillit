/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 07:55:46 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 15:29:10 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		filler_check_place(char **sqr, t_coord *coord, int *ij, int size)
{
	t_coord	*current;

	current = coord;
	while (current != NULL)
	{
		if (current->i + ij[0] >= size && current->j + ij[1] >= size)
			return (-1);
		if (current->i + ij[0] >= size || current->j + ij[1] >= size ||
				sqr[ij[0] + current->i][ij[1] + current->j] != DOT)
			return (0);
		current = current->next;
	}
	return (1);
}

int		filler(char **sqr, t_etrimino *head, int size, int *ij)
{
	t_etrimino	*current;
	t_coord		*c_coord;

	current = head;
	c_coord = current->coord;
	if (filler_check_place(sqr, c_coord, ij, size))
	{
		while (c_coord != NULL)
		{
			sqr[ij[0] + c_coord->i][ij[1] + c_coord->j] = current->c;
			c_coord = c_coord->next;
		}
		return (1);
	}
	return (0);
}
