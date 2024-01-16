/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_print_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:13:33 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/05 14:21:36 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_data *data)
{
	data->i = 0;
	data->y = 0;
	while (data->map[data->i])
	{
		second_print_map(data);
		data->y += 60;
		data->i++;
	}
}

void	third_print_map(t_data *data)
{
	if (data->map[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor->asset, data->map_x + data->x, data->map_y + data->y);
	if (data->map[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->skel->asset, data->map_x + data->x, data->map_y + data->y);
	if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->coin->asset, data->map_x + data->x, data->map_y + data->y);
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->ladder->asset, data->map_x + data->x, data->map_y + data->y);
}

void	second_print_map(t_data *data)
{
	data->j = 0;
	data->x = 0;
	while (data->map[data->i][data->j])
	{
		if (data->map[data->i][data->j] == '1')
			mlx_put_image_to_window(data->mlx, data->win,
				data->side_wall->asset, data->map_x + data->x,
				data->map_y + data->y);
		if (data->map[data->i][data->j] == '0')
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor->asset, data->map_x + data->x,
				data->map_y + data->y);
		third_print_map(data);
		data->x += 60;
		data->j++;
	}
}
