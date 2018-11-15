/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:58:48 by astrole           #+#    #+#             */
/*   Updated: 2018/11/10 01:58:49 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_world.h"

static void		draw_lines(t_world *world, t_window *window,
	t_player *player, t_grid *grid)
{
	world->wallx -= floor(world->wallx);
	world->texx = (int)(world->wallx * (double)grid->images[world->texnum]->w);
	if (world->side == 0 && world->raydir.x > 0)
		world->texx = grid->images[world->texnum]->w - world->texx - 1;
	if (world->side == 1 && world->raydir.y < 0)
		world->texx = grid->images[world->texnum]->w - world->texx - 1;
	world->y = world->draw_points.x;
	while (world->y < world->draw_points.y)
	{
		world->d = world->y * 256 -
		window->height * 128 + world->lineheight * 128;
		world->texy = ((world->d * grid->images[world->texnum]->h) /
			world->lineheight) / 256;
		world->i_color = get_pixel(grid->images[world->texnum],
			(t_vector2i){world->texx, world->texy});
		if (world->side == 1)
			world->i_color = (world->i_color >> 1) & 8355711;
		set_pixel(player->surf,
			(t_vector2i){world->x, world->y}, world->i_color);
		world->y++;
	}
}

static void		draw_init_line(t_world *world, t_window *window,
	t_player *player, t_grid *grid)
{
	if (world->side == 0)
		world->walldist = (world->map_pos.x - player->pos.x +
							(1 - world->step.x) / 2) / world->raydir.x;
	else
		world->walldist = (world->map_pos.y - player->pos.y +
							(1 - world->step.y) / 2) / world->raydir.y;
	world->lineheight = (int)(window->height / world->walldist);
	world->draw_points.x = -world->lineheight / 2 + window->height / 2;
	if (world->draw_points.x < 0)
		world->draw_points.x = 0;
	world->draw_points.y = world->lineheight / 2 + window->height / 2;
	if (world->draw_points.y >= window->height)
		world->draw_points.y = window->height - 1;
	if (world->side == 0 && world->raydir.x < 0)
		world->texnum = 0;
	if (world->side == 0 && world->raydir.x > 0)
		world->texnum = 1;
	if (world->side == 1 && world->raydir.y < 0)
		world->texnum = 2;
	if (world->side == 1 && world->raydir.y > 0)
		world->texnum = 3;
	if (world->side == 0)
		world->wallx = player->pos.y + world->walldist * world->raydir.y;
	else
		world->wallx = player->pos.x + world->walldist * world->raydir.x;
}

static void		draw_hit_loop(t_world *world,
	t_grid *grid)
{
	while (world->hit == 0)
	{
		if (world->sidedist.x < world->sidedist.y)
		{
			world->sidedist.x += world->deltadist.x;
			world->map_pos.x += world->step.x;
			world->side = 0;
		}
		else
		{
			world->sidedist.y += world->deltadist.y;
			world->map_pos.y += world->step.y;
			world->side = 1;
		}
		if ((world->map_pos.x < 0 || world->map_pos.y < 0 ||
			world->map_pos.x >= grid->grid_height ||
			world->map_pos.y >= grid->grid_width)
			&& (world->error = 1) == 1)
			break ;
		if (grid->grid[(int)world->map_pos.x][(int)world->map_pos.y] > 0)
			world->hit = 1;
	}
}

static void		draw_init_values(t_world *world,
	t_player *player)
{
	if (world->raydir.x < 0)
	{
		world->step.x = -1;
		world->sidedist.x = (player->pos.x - world->map_pos.x)
					* world->deltadist.x;
	}
	else
	{
		world->step.x = 1;
		world->sidedist.x = (world->map_pos.x + 1.0 - player->pos.x)
					* world->deltadist.x;
	}
	if (world->raydir.y < 0)
	{
		world->step.y = -1;
		world->sidedist.y = (player->pos.y - world->map_pos.y)
					* world->deltadist.y;
	}
	else
	{
		world->step.y = 1;
		world->sidedist.y = (world->map_pos.y +
			1.0 - player->pos.y) * world->deltadist.y;
	}
	world->hit = 0;
}

void			draw_world(t_window *window, t_player *player,
	t_grid *grid)
{
	t_world world;

	world.x = -1;
	world.side = 0;
	world.error = 0;
	while (++world.x < window->width)
	{
		init_values(&world, window, player);
		draw_init_values(&world, player);
		draw_hit_loop(&world, grid);
		if (world.error != 0)
		{
			world.error = 0;
			continue;
		}
		draw_init_line(&world, window, player, grid);
		draw_lines(&world, window, player, grid);
	}
	draw_surf(window->renderer, player->surf, (t_vector2i){0, 0});
	wipe_surface(player->surf,
		SDL_MapRGB(player->surf->format, 255, 255, 255));
}
