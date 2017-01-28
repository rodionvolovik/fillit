/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:13:08 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 14:54:36 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_matrix(char **sqr)
{
	int	col;

	col = -1;
	while (sqr[++col] != NULL)
		free(sqr[col]);
	free(sqr);
}

void	free_lst(t_etrimino **head)
{
	t_etrimino	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	free_all(t_etrimino **head, char *map, char **sqr)
{
	free_lst(head);
	free(map);
	free_matrix(sqr);
}
