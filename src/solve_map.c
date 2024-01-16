/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:47:16 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/13 13:58:02 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *s, char c);

char	**solvable(char **map, int i, int j)
{
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E')
	{
		map[i - 1][j] = 'A';
		solvable(map, i - 1, j);
	}
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'E')
	{
		map[i + 1][j] = 'A';
		solvable(map, i + 1, j);
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E')
	{
		map[i][j - 1] = 'A';
		solvable(map, i, j - 1);
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E')
	{
		map[i][j + 1] = 'A';
		solvable(map, i, j + 1);
	}
	return (map);
}

char	**find_p(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				map = solvable(map, i, j);
				return (map);
			}
			j++;
		}
		i++;
	}
	return (map);
}

int	check_solve_map(char **solve_map, char **og_map, int coin_exit)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (og_map[i])
	{
		j = 0;
		while (og_map[i][j])
		{
			if ((og_map[i][j] == 'C' || og_map[i][j] == 'E')
				&& solve_map[i][j] == 'A')
				count++;
			j++;
		}
		i++;
	}
	if (count == coin_exit)
		return (0);
	else
		return (1);
}
