/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 02:00:27 by astrole           #+#    #+#             */
/*   Updated: 2018/11/14 02:00:28 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_full_map(t_grid *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->grid_height)
	{
		j = 0;
		while (j < map->grid_width)
		{
			if (i == 0 || i == map->grid_height - 1)
			{
				if (map->grid[i][j] == 0)
					return (0);
			}
			else
			{
				if (j == 0 || j == map->grid_width - 1)
					if (map->grid[i][j] == 0)
						return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
