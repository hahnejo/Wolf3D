/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:51:58 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 00:51:59 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MAP_H
# define WOLF3D_MAP_H

# include "vector.h"
# include "libft.h"
# include "surface.h"

typedef struct	s_grid
{
	int			**grid;
	SDL_Surface	**images;
	int			images_length;
	int			grid_width;
	int			grid_height;
}				t_grid;

SDL_Surface		**load_map_images(char **names);
void			free_grid(t_grid *grid);
t_grid			*new_grid(char *filename);
char			**get_image_names(char *filename);
int				check_full_map(t_grid *map);

#endif
