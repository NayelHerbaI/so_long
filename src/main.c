/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:16:38 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/13 19:53:10 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_asset(t_character *object, t_data *data);

int	error_handling(int ac, char **av, char **map, t_data *data)
{
	(void)av;
	if (ac != 2)
		return (1);
	if (check_map(map, data) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	void	*mlx;

	if (ac != 2)
		return (write(1, "Error\n", 6));
	data = malloc(sizeof(t_data));
	alloc_mem(data);
	setup_data(data, av[1]);
	mlx = data->mlx;
	setup_wall_and_floor(data);
	setup_character(data);
	if (error_handling(ac, av, data->map, data) == 1)
	{
		write(1, "Error\n", 6);
		exit_game(data, 3);
	}
	mlx_key_hook(data->win, key_handling, (t_data *)data);
	print_map(data);
	mlx_loop(data->mlx);
	close(data->fd);
	return (0);
}
