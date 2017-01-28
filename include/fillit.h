/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:44:20 by rvolovik          #+#    #+#             */
/*   Updated: 2016/12/19 15:13:56 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# include <fcntl.h>
# include <stdio.h>

# define USAGE ("usage: ./filit [map_file]")
# define ERROR ("error")
# define BUFSIZE 1000
# define TETRIMINOS_Q 19
# define DOT '.'
# define BLOCK '#'

typedef struct			s_etrimino
{
	char				c;
	struct s_coord		*coord;
	struct s_etrimino	*next;
}						t_etrimino;

typedef struct			s_coord
{
	int					i;
	int					j;
	struct s_coord		*next;
}						t_coord;

void					error_exit(char *error_input);
char					*read_map(char *av);
void					print_matrix(char **m);
void					init_patterns(char **figures);
int						valid_figurs(char *tmp, int i, int shift);
char					*parse_figure(char *tmp);
int						check_figure(char *tmp);
int						check_map(char *buf, int map_chars);
t_etrimino				*ft_create_elem(char **figure, char c);
void					ft_list_push(t_etrimino **head, t_etrimino *new_m);
t_etrimino				*ft_create_matrix(char *s, t_etrimino *head);
int						figures_num(char *s);
int						ft_sqrt(int n);
int						min_square_size(int figures_num);
char					**create_square(int size);
int						filler(char **sqr, t_etrimino *head, int size, int *ij);
int						solve(t_etrimino *head, char **sqr, int size);
t_coord					*ft_create_elem_coords(int i, int j);
void					ft_list_push_coords(t_coord **coord, t_coord *new_m);
t_coord					*find_figure_coords(char **figure);
void					free_matrix(char **sqr);
void					free_lst(t_etrimino **head);
void					free_all(t_etrimino **head, char *map, char **sqr);

#endif
