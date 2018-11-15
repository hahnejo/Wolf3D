/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:56:38 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:56:39 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
# define WOLF3D_WOLF_H
# include "window.h"
# include "player.h"
# include "map.h"
# include <SDL.h>
# include <SDL_image.h>

typedef struct	s_wolf
{
	t_window	*window;
	t_grid		*map;
	t_player	*player;
	char		*str;
}				t_wolf;

t_wolf			*create_wolf(char *filename);
void			run_wolf(t_wolf *wolf);
void			free_wolf(t_wolf *wolf);

#endif
