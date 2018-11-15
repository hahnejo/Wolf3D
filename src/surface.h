/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:41:21 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:41:23 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_SURFACE_H
# define WOLF3D_SURFACE_H
# include <SDL.h>
# include <SDL_image.h>
# include "vector.h"

SDL_Surface		*load_image_surface(const char *name);
SDL_Surface		*wipe_surface(SDL_Surface *surface, int color);
uint32_t		get_pixel(SDL_Surface *surface, t_vector2i pos);
void			set_pixel(SDL_Surface *surface, t_vector2i pos, uint32_t color);
void			draw_surf(SDL_Renderer *renderer, SDL_Surface *surface,
t_vector2i pos);
#endif
