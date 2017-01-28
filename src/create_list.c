/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:30:53 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 14:26:22 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			figures_num(char *s)
{
	int		tetriminos;

	tetriminos = 0;
	while (*s)
	{
		if (*s++ == BLOCK)
			tetriminos++;
	}
	return (tetriminos / 4);
}

void		parse_coords(t_coord *coord)
{
	int		mini;
	int		minj;
	t_coord	*tmp;
	t_coord *res;

	tmp = coord;
	res = coord;
	mini = 4;
	minj = 4;
	while (tmp != NULL)
	{
		if (tmp->i < mini)
			mini = tmp->i;
		if (tmp->j < minj)
			minj = tmp->j;
		tmp = tmp->next;
	}
	while (res != NULL)
	{
		res->i -= mini;
		res->j -= minj;
		res = res->next;
	}
}

t_etrimino	*ft_create_elem(char **figure, char c)
{
	t_etrimino	*m;

	m = (t_etrimino *)malloc(sizeof(t_etrimino));
	m->c = c;
	m->coord = find_figure_coords(figure);
	parse_coords(m->coord);
	m->next = NULL;
	free_matrix(figure);
	return (m);
}

void		ft_list_push(t_etrimino **head, t_etrimino *new_m)
{
	t_etrimino *tmp;

	tmp = *head;
	if (*head == NULL)
	{
		*head = new_m;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_m;
	}
}

t_etrimino	*ft_create_matrix(char *s, t_etrimino *head)
{
	char	*tmp;
	int		start;
	char	c;
	int		index;
	int		i;

	index = figures_num(s);
	start = 0;
	i = 1;
	c = 'A' - 1;
	while (index-- > 0)
	{
		c++;
		tmp = ft_strsub(s, start, 20);
		start += 21;
		ft_list_push(&head, ft_create_elem(ft_strsplit(tmp, '\n'), c));
		if (*s == '\n')
			s++;
		if (*s == '\0')
			break ;
		free(tmp);
	}
	return (head);
}
