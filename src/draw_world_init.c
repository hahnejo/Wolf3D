/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:23:33 by astrole           #+#    #+#             */
/*   Updated: 2018/11/10 02:23:34 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_world.h"

void	init_values(t_world *world, t_window *window,
	t_player *player)
{
	world->camerax = 2 * world->x / (double)window->width - 1;
	world->raydir.x = player->dir.x + player->plane.x * world->camerax;
	world->raydir.y = player->dir.y + player->plane.y * world->camerax;
	world->map_pos.x = (int)player->pos.x;
	world->map_pos.y = (int)player->pos.y;
	world->deltadist.x = fabs(1 / world->raydir.x);
	world->deltadist.y = fabs(1 / world->raydir.y);
}
