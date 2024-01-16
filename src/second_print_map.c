/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_print_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:55:35 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/05 14:16:23 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	second_check_coin_and_exit(t_data *data,
		int key, int char_pos_x, int char_pos_y)
{
	if (key == 1 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x + 1][char_pos_y] == 'C')
	{
		data->map[char_pos_x + 1][char_pos_y] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 0);
	}
	if (key == 2 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x][char_pos_y + 1] == 'C')
	{
		data->map[char_pos_x][char_pos_y + 1] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 0);
	}
}

int	check_ifs(t_data *data, int key, int char_pos_x, int char_pos_y)
{
	if (key == 13 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x - 1][char_pos_y] != '1'
		&& data->map[char_pos_x - 1][char_pos_y] != 'E'
		&& data->map[char_pos_x - 1][char_pos_y] != 'C')
		return (1);
	if (key == 0 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x][char_pos_y - 1] != '1'
		&& data->map[char_pos_x][char_pos_y - 1] != 'E'
		&& data->map[char_pos_x][char_pos_y - 1] != 'C')
		return (2);
	if (key == 1 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x + 1][char_pos_y] != '1'
		&& data->map[char_pos_x + 1][char_pos_y] != 'E'
		&& data->map[char_pos_x + 1][char_pos_y] != 'C')
		return (3);
	if (key == 2 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x][char_pos_y + 1] != '1'
		&& data->map[char_pos_x][char_pos_y + 1] != 'E'
		&& data->map[char_pos_x][char_pos_y + 1] != 'C')
		return (4);
	return (0);
}

void	move_da_booty(t_data *data, int char_pos_x, int char_pos_y, int bin)
{
	if (bin == 1)
	{
		data->map[char_pos_x - 1][char_pos_y] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 1);
	}
	if (bin == 2)
	{
		data->map[char_pos_x][char_pos_y - 1] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 1);
	}
	if (bin == 3)
	{
		data->map[char_pos_x + 1][char_pos_y] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 1);
	}
	if (bin == 4)
	{
		data->map[char_pos_x][char_pos_y + 1] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 1);
	}
}
