/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:01:18 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/09 17:06:40 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_char_pos(t_data *data, char c, char pos)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == c && pos == 'x')
				return (i);
			if (data->map[i][j] == c && pos == 'y')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

void	moves_and_coin(t_data *data, int bin)
{
	if (bin == 0)
		data->coin_collected++;
	data->moves++;
	ft_putnbr(data->moves);
	ft_putchar('\n');
}

void	check_coin_and_exit(t_data *data, int key,
		int char_pos_x, int char_pos_y)
{
	if (key == 13 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x - 1][char_pos_y] == 'C')
	{
		data->map[char_pos_x - 1][char_pos_y] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 0);
	}
	if (key == 0 && char_pos_x > 0 && char_pos_y > 0
		&& data->map[char_pos_x][char_pos_y - 1] == 'C')
	{
		data->map[char_pos_x][char_pos_y - 1] = 'P';
		data->map[char_pos_x][char_pos_y] = '0';
		moves_and_coin(data, 0);
	}
	second_check_coin_and_exit(data, key, char_pos_x, char_pos_y);
	check_exit(data, key, char_pos_x, char_pos_y);
}

void	move_on_map(t_data *data, int key)
{
	int	char_pos_x;
	int	char_pos_y;

	char_pos_x = find_char_pos(data, 'P', 'x');
	char_pos_y = find_char_pos(data, 'P', 'y');
	if (check_ifs(data, key, char_pos_x, char_pos_y) == 1)
		move_da_booty(data, char_pos_x, char_pos_y, 1);
	if (check_ifs(data, key, char_pos_x, char_pos_y) == 2)
		move_da_booty(data, char_pos_x, char_pos_y, 2);
	if (check_ifs(data, key, char_pos_x, char_pos_y) == 3)
		move_da_booty(data, char_pos_x, char_pos_y, 3);
	if (check_ifs(data, key, char_pos_x, char_pos_y) == 4)
		move_da_booty(data, char_pos_x, char_pos_y, 4);
	check_coin_and_exit(data, key, char_pos_x, char_pos_y);
}

int	key_handling(int key, t_data *data)
{
	if (key == 53)
		exit_game(data, 1);
	if (key == 13)
		move_on_map(data, key);
	else if (key == 0)
		move_on_map(data, key);
	else if (key == 1)
		move_on_map(data, key);
	else if (key == 2)
		move_on_map(data, key);
	mlx_clear_window(data->mlx, data->win);
	print_map(data);
	return (key);
}
