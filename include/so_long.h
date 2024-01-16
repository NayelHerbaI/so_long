/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:56 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/13 19:56:52 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_character
{
	void	*asset;
	int		size_x;
	int		size_y;
	int		pos_x;
	int		pos_y;
}				t_character;

typedef struct s_data
{
	int			i;
	int			j;
	int			x;
	int			y;
	void		*mlx;
	void		*win;
	int			fd;
	char		*buf;
	char		**map;
	char		**solve_map;
	int			map_x;
	int			map_y;
	int			coin_collected;
	int			moves;
	int			nb_coins;
	t_character	*side_wall;
	t_character	*floor;
	t_character	*coin;
	t_character	*skel;
	t_character	*ladder;
}				t_data;

int		ft_strlen(char *str);
void	setup_data(t_data *data, char *path);
void	setup_character(t_data *data);
int		check_map_size(char **map);
int		check_extern_walls(char **map);
int		check_map(char **map, t_data *data);
int		find_tab_size(char *s, char c);
char	*ft_copy(char *s, char c);
char	**second_split(char *s, char c, char **tab);
char	**ft_split(char *s, char c);
void	print_map(t_data *data);
void	alloc_mem(t_data *data);
void	setup_character(t_data *data);
void	setup_data(t_data *data, char *path);
void	setup_wall_and_floor(t_data *data);
void	setup_map_pos(t_data *data);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		find_char_pos(t_data *data, char c, char pos);
void	move_on_map(t_data *data, int key);
int		key_handling(int key, t_data *data);
void	exit_game(t_data *data, int alaid);
void	check_exit(t_data *data, int key, int char_pos_x, int char_pos_y);
void	moves_and_coin(t_data *data, int bin);
char	**solvable(char **map, int i, int j);
char	**find_p(char **map);
int		check_solve_map(char **solve_map, char **og_map, int coin_exit);
void	print_map(t_data *data);
void	second_print_map(t_data *data);
void	third_print_map(t_data *data);
void	check_coin_and_exit(t_data *data, int key,
			int char_pos_x, int char_pos_y);
void	second_check_coin_and_exit(t_data *data, int key,
			int char_pos_x, int char_pos_y);
int		check_ifs(t_data *data, int key, int char_pos_x, int char_pos_y);
void	move_da_booty(t_data *data, int char_pos_x, int char_pos_y, int bin);

#endif
