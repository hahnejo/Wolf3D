/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:03:13 by astrole           #+#    #+#             */
/*   Updated: 2018/11/10 02:03:14 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "map_math.h"
#include "libft.h"
#include <math.h>

t_player		*new_player(t_vector2f window_size)
{
	t_player *player;

	player = ft_memalloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->surf = SDL_CreateRGBSurface(0,
		(int)window_size.x, (int)window_size.y, 32, 0, 0, 0, 0);
	if (!player->surf)
		return (NULL);
	return (player);
}

void			spawn_player(t_player *player, t_grid *map)
{
	int i;
	int j;
	int done;

	i = 0;
	done = 0;
	while (i < map->grid_height && !done)
	{
		j = 0;
		while (j < map->grid_width)
		{
			if (map->grid[i][j] == 0)
			{
				done = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	player->pos = (t_vector2f){i - 0.6, j + 0.5};
	player->init_pos = player->pos;
}

void			free_player(t_player *player)
{
	SDL_FreeSurface(player->surf);
	free(player);
}
