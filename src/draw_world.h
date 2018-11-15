/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:25:09 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:25:10 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DRAW_WORLD_H
# define WOLF3D_DRAW_WORLD_H

# include "vector.h"
# include "map.h"
# include "player.h"
# include "window.h"

typedef struct		s_world
{
	int				x;
	int				y;
	int				hit;
	int				side;
	int				lineheight;
	int				texnum;
	int				texx;
	int				texy;
	int				d;
	int				error;
	unsigned int	i_color;
	double			camerax;
	double			walldist;
	double			wallx;
	t_vector2f		step;
	t_vector2f		raydir;
	t_vector2f		map_pos;
	t_vector2f		sidedist;
	t_vector2f		deltadist;
	t_vector2i		draw_points;
}					t_world;

void				draw_world(t_window *window,
		t_player *player, t_grid *grid);
void				init_values(t_world *world, t_window *window,
		t_player *player);

#endif
