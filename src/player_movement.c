/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:10:34 by astrole           #+#    #+#             */
/*   Updated: 2018/11/10 02:10:35 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void		rotator_right(t_player *player, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x *
cos(-rot_speed) - player->dir.y * sin(-rot_speed);
	player->dir.y = old_dir_x *
sin(-rot_speed) + player->dir.y * cos(-rot_speed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x *
cos(-rot_speed) - player->plane.y * sin(-rot_speed);
	player->plane.y = old_plane_x *
sin(-rot_speed) + player->plane.y * cos(-rot_speed);
}

static void		rotator_left(t_player *player, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x *
cos(rot_speed) - player->dir.y * sin(rot_speed);
	player->dir.y = old_dir_x *
sin(rot_speed) + player->dir.y * cos(rot_speed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x *
cos(rot_speed) - player->plane.y * sin(rot_speed);
	player->plane.y = old_plane_x *
sin(rot_speed) + player->plane.y * cos(rot_speed);
}

static void		up_down_move(t_player *player,
	t_grid *map, int key, double move_speed)
{
	double x;
	double y;

	if (key == SDLK_UP)
	{
		x = player->pos.x + player->dir.x * move_speed;
		y = player->pos.y + player->dir.y * move_speed;
		if (x >= 0 && y < map->grid_width && y >= 0 &&
			x < map->grid_height && map->grid[(int)x][(int)y] == 0)
		{
			player->pos.x = x;
			player->pos.y = y;
		}
	}
	else if (key == SDLK_DOWN)
	{
		x = player->pos.x - player->dir.x * move_speed;
		y = player->pos.y - player->dir.y * move_speed;
		if (x >= 0 && y < map->grid_width && y >= 0 &&
			x < map->grid_height && map->grid[(int)x][(int)y] == 0)
		{
			player->pos.x = x;
			player->pos.y = y;
		}
	}
}

void			player_move(t_player *player, int key, t_grid *map)
{
	double move_speed;
	double rot_speed;

	move_speed = 0.5;
	rot_speed = 0.5;
	if (key == SDLK_UP || key == SDLK_DOWN)
		up_down_move(player, map, key, move_speed);
	if (key == SDLK_RIGHT)
		rotator_right(player, rot_speed);
	if (key == SDLK_LEFT)
		rotator_left(player, rot_speed);
	if (key == SDLK_r)
		player->pos = player->init_pos;
}
