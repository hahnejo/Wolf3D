/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:55:03 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 00:55:05 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_PLAYER_H
# define WOLF3D_PLAYER_H

# include "vector.h"
# include "map.h"
# include "window.h"
# include <SDL.h>

typedef struct	s_player
{
	t_vector2f	pos;
	t_vector2f	init_pos;
	t_vector2f	dir;
	t_vector2f	plane;
	SDL_Surface	*surf;
}				t_player;

void			spawn_player(t_player *player, t_grid *map);
t_player		*new_player(t_vector2f window_size);
void			draw_world(t_window *window, t_player *player, t_grid *grid);
void			player_move(t_player *player, int key, t_grid *map);
void			free_player(t_player *player);

#endif
