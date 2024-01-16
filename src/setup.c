/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:07:42 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/09 16:23:03 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	alloc_mem(t_data *data)
{
	data->side_wall = malloc(sizeof(t_character));
	data->floor = malloc(sizeof(t_character));
	data->coin = malloc(sizeof(t_character));
	data->skel = malloc(sizeof(t_character));
	data->ladder = malloc(sizeof(t_character));
}

void	setup_character(t_data *data)
{
	data->coin->pos_x = 700;
	data->coin->pos_y = 300;
	data->coin->asset = mlx_xpm_file_to_image(data->mlx, "last/coin.xpm",
			&data->coin->size_x, &data->coin->size_y);
	data->skel->pos_x = 700;
	data->skel->pos_y = 300;
	data->skel->asset = mlx_xpm_file_to_image(data->mlx, "last/s.xpm",
			&data->skel->size_x, &data->skel->size_y);
	data->ladder->pos_x = 700;
	data->ladder->pos_y = 300;
	data->ladder->asset = mlx_xpm_file_to_image(data->mlx, "last/ladder.xpm",
			&data->ladder->size_x, &data->ladder->size_y);
	data->coin_collected = 0;
	data->moves = 0;
	data->nb_coins = 0;
}

void	setup_data(t_data *data, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->fd = open(path, O_RDONLY);
	data->buf = malloc(100000);
	read(data->fd, data->buf, 100000);
	data->map = ft_split(data->buf, '\n');
	data->solve_map = ft_split(data->buf, '\n');
	setup_map_pos(data);
	data->mlx = mlx_init();
	while (data->map[i][j])
		j++;
	while (data->map[i])
		i++;
	data->win = mlx_new_window(data->mlx, j * 65, i * 65, "so_long");
}

void	setup_wall_and_floor(t_data *data)
{
	data->side_wall->pos_x = 0;
	data->side_wall->pos_y = 0;
	data->side_wall->asset = mlx_xpm_file_to_image(data->mlx, "last/flame.xpm",
			&data->side_wall->size_x, &data->side_wall->size_y);
	data->floor->pos_x = 0;
	data->floor->pos_y = 0;
	data->floor->asset = mlx_xpm_file_to_image(data->mlx,
			"last/floor.xpm", &data->floor->size_x, &data->floor->size_y);
}

void	setup_map_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = ft_strlen(data->map[0]);
	while (data->map[y])
		y++;
}
