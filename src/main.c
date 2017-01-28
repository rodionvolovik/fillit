/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:42:32 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 14:57:24 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char		*map;
	t_etrimino	*head;
	char		**sqr;
	int			size;

	head = NULL;
	map = NULL;
	if (ac == 2)
		map = read_map(av[1]);
	else
		error_exit(USAGE);
	head = ft_create_matrix(map, head);
	size = min_square_size(figures_num(map));
	sqr = create_square(size);
	while (!solve(head, sqr, size))
	{
		size += 1;
		free_matrix(sqr);
		sqr = create_square(size);
	}
	print_matrix(sqr);
	free_all(&head, map, sqr);
	return (0);
}
