/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:51:48 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/10 15:51:51 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_map(char *av)
{
	char	buf[BUFSIZE];
	int		fd;
	int		map_chars;
	char	*map;

	map_chars = 0;
	if ((fd = open(av, O_RDONLY)) > 0)
	{
		if ((map_chars = read(fd, buf, BUFSIZE)) < 1)
			error_exit(ERROR);
	}
	map = ft_strsub(buf, 0, map_chars);
	close(fd);
	if (map[map_chars - 1] == '\n' && map[map_chars - 2] == '\n')
		error_exit(ERROR);
	if (!check_map(map, map_chars) || map_chars == 0)
		error_exit(ERROR);
	return (map);
}
