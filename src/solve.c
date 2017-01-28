/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:09:42 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 15:31:22 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_sqrt(int n)
{
	int		i;

	i = 0;
	while (i <= n / 2)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (0);
}

int		min_square_size(int figures_num)
{
	int		size;

	size = figures_num * 4;
	while (ft_sqrt(size) == 0)
		size++;
	size = ft_sqrt(size);
	return (size);
}

char	**create_square(int size)
{
	char	**sqr;
	char	**ret;
	int		i;

	i = 0;
	sqr = (char **)malloc(sizeof(char *) * (size + 1));
	ret = sqr;
	while (i++ < size)
	{
		*sqr = ft_strnew(size);
		ft_memset(*sqr, DOT, size);
		sqr++;
	}
	*sqr = NULL;
	return (ret);
}

void	clear_place(char c, char **sqr)
{
	int		i;
	int		j;

	i = 0;
	while (sqr[i] != NULL)
	{
		j = 0;
		while (sqr[i][j] != '\0')
		{
			if (sqr[i][j] == c)
				sqr[i][j] = DOT;
			j++;
		}
		i++;
	}
}

int		solve(t_etrimino *head, char **sqr, int size)
{
	int		ij[2];
	int		flag;

	ij[0] = 0;
	ij[1] = 0;
	if (!(head))
		return (1);
	while (ij[0] < size && ij[1] < size)
	{
		while ((!(flag = filler(sqr, head, size, ij))) && ij[0] < size)
		{
			ij[1] = (ij[1] == size - 1) ? 0 : ij[1] + 1;
			ij[0] = (ij[1] == 0) ? ij[0] + 1 : ij[0];
		}
		if (flag == 1 && solve(head->next, sqr, size))
			return (1);
		clear_place(head->c, sqr);
		ij[1] = (ij[1] >= size - 1) ? 0 : ij[1] + 1;
		ij[0] = (ij[1] == 0) ? ij[0] + 1 : ij[0];
	}
	return (0);
}
