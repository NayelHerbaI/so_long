/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:10:31 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/13 19:52:02 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_asset(t_character *object, t_data *data)
{
	mlx_destroy_image(data->mlx, object->asset);
	free(object);
}

void	exit_game(t_data *data, int alaid)
{
	int	i;

	if (alaid == 0)
		moves_and_coin(data, 1);
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		free(data->solve_map[i]);
		i++;
	}
	free_asset(data->side_wall, data);
	free_asset(data->floor, data);
	free_asset(data->coin, data);
	free_asset(data->skel, data);
	free_asset(data->ladder, data);
	free(data->buf);
	free(data->map);
	free(data->solve_map);
	free(data);
	exit(1);
}

void	check_exit(t_data *data, int key, int char_pos_x, int char_pos_y)
{
	int	check;

	check = data->nb_coins - data->coin_collected;
	if (key == 13 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x - 1][char_pos_y] == 'E' && check == 0)
		exit_game(data, 0);
	if (key == 0 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x][char_pos_y - 1] == 'E' && check == 0)
		exit_game(data, 0);
	if (key == 1 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x + 1][char_pos_y] == 'E' && check == 0)
		exit_game(data, 0);
	if (key == 2 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x][char_pos_y + 1] == 'E' && check == 0)
		exit_game(data, 0);
}
