/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:30 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/13 14:13:20 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_size(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_mid(char **map, int size)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]) - 1;
	i = 1;
	while (i < size)
	{
		if (map[i][0] != '1' || map[i][len] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_extern_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (1);
		j++;
	}
	while (map[i + 1])
		i++;
	j = 0;
	if (check_mid(map, i) == 1)
		return (1);
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	second_check_map(char **map, t_data *data, int map_player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				data->nb_coins++;
			if (map[i][j] == 'P' || map[i][j] == 'E')
				map_player++;
			j++;
		}
		i++;
	}
	if (data->nb_coins == 0)
		return (1);
	return (map_player);
}

int	check_map(char **map, t_data *data)
{
	int	i;
	int	coin;
	int	map_player;

	map_player = 0;
	coin = 0;
	i = 0;
	if (map == NULL || check_extern_walls(map) == 1 || check_map_size(map) == 1)
		return (1);
	map_player = second_check_map(map, data, map_player);
	if (map_player != 2)
		return (1);
	if (check_solve_map(find_p(data->solve_map),
			data->map, data->nb_coins + 1) == 1)
		return (1);
	return (0);
}
