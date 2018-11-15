/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:51:43 by astrole           #+#    #+#             */
/*   Updated: 2018/11/07 07:51:44 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "frame.h"

#define FATAL_ERROR(message) ({ft_putendl(message); NULL;})

t_wolf			*create_wolf(char *filename)
{
	t_wolf *wolf;

	wolf = ft_memalloc(sizeof(t_wolf));
	if (!wolf)
		return (NULL);
	wolf->window = create_window(1080, 720);
	if (!wolf->window)
		return (FATAL_ERROR("Failed to create window!"));
	wolf->player = new_player(
(t_vector2f){wolf->window->width, wolf->window->height});
	if (!wolf->player)
		return (FATAL_ERROR("Failed to create player!"));
	wolf->map = new_grid(filename);
	if (!wolf->map)
		return (FATAL_ERROR("Failed to create map!"));
	spawn_player(wolf->player, wolf->map);
	return (wolf);
}

static int		wolf_events(t_wolf *wolf)
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (1);
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			player_move(wolf->player, e.key.keysym.sym, wolf->map);
		}
	}
	return (0);
}

static void		wolf_draw(t_wolf *wolf)
{
	SDL_SetRenderDrawColor(wolf->window->renderer, 255, 255, 255, 255);
	SDL_RenderClear(wolf->window->renderer);
	SDL_FillRect(wolf->player->surf,
&(SDL_Rect){0, wolf->window->height / 2,
	wolf->window->width, wolf->window->height / 2},
SDL_MapRGB(wolf->player->surf->format, 160, 160, 160));
	SDL_FillRect(wolf->player->surf,
&(SDL_Rect){0, 0, wolf->window->width,
	wolf->window->height / 2},
SDL_MapRGB(wolf->player->surf->format, 89, 151, 249));
	draw_world(wolf->window, wolf->player, wolf->map);
	SDL_RenderPresent(wolf->window->renderer);
}

void			run_wolf(t_wolf *wolf)
{
	int quit;
	int target_fps;
	int start_time;

	target_fps = 60;
	quit = 0;
	while (!quit)
	{
		quit = wolf_events(wolf);
		start_time = SDL_GetTicks();
		wolf_events(wolf);
		wolf_draw(wolf);
		limit_frame(target_fps, start_time);
	}
}

void			free_wolf(t_wolf *wolf)
{
	free_player(wolf->player);
	free_grid(wolf->map);
	free_window(wolf->window);
	free(wolf);
}
