/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:56:18 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 14:21:21 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_patterns(char **figures)
{
	figures[0] = "###...#.........";
	figures[1] = "#...#..##.......";
	figures[2] = "#...###.........";
	figures[3] = "##..#...#.......";
	figures[4] = "###.#...........";
	figures[5] = "##...#...#......";
	figures[6] = "#.###...........";
	figures[7] = "#...#...##......";
	figures[8] = "###..#..........";
	figures[9] = "#..##...#.......";
	figures[10] = "#..###..........";
	figures[11] = "#...##..#.......";
	figures[12] = "##.##...........";
	figures[13] = "#...##...#......";
	figures[14] = "##...##.........";
	figures[15] = "#..##..#........";
	figures[16] = "####............";
	figures[17] = "#...#...#...#...";
	figures[18] = "##..##..........";
}

int		valid_figurs(char *tmp, int i, int shift)
{
	char	*figures[19];

	init_patterns(figures);
	if (ft_strncmp(tmp, figures[i], 16 - shift) != 0)
		return (0);
	return (1);
}

char	*parse_figure(char *tmp)
{
	char	*fig;
	char	*res;
	int		i;

	i = 0;
	fig = (char *)malloc(sizeof(char) * 17);
	res = fig;
	fig[16] = '\0';
	while (*tmp)
	{
		i++;
		if (*tmp == BLOCK || *tmp == DOT)
			*fig++ = *tmp;
		if (i == 5)
		{
			if (*tmp != '\n')
				error_exit(ERROR);
			i = 0;
		}
		tmp++;
	}
	return (res);
}

int		check_figure(char *tmp)
{
	int		i;
	int		shift;

	i = 0;
	shift = 0;
	tmp = parse_figure(tmp);
	while (*tmp != BLOCK && *tmp)
	{
		shift++;
		tmp++;
	}
	if (ft_strlen(tmp) != 0)
	{
		while (i < TETRIMINOS_Q)
		{
			if (valid_figurs(tmp, i, shift) == 0)
				i++;
			else
				return (1);
		}
	}
	return (0);
}

int		check_map(char *buf, int map_chars)
{
	char	*tmp;
	int		start;

	start = 0;
	while (map_chars > start)
	{
		tmp = ft_strsub(buf, start, 20);
		start += 20;
		if (check_figure(tmp) == 0)
			return (0);
		if (buf[start] == '\n' || buf[start] == '\0')
			start++;
		else
			error_exit(ERROR);
		free(tmp);
	}
	return (1);
}
