/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:40:36 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:40:37 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "surface.h"

SDL_Surface	*load_image_surface(const char *name)
{
	SDL_Surface	*output_surface;
	SDL_Surface	*loaded_surface;

	loaded_surface = IMG_Load(name);
	if (!loaded_surface)
		return (NULL);
	output_surface = SDL_ConvertSurface(loaded_surface,
		loaded_surface->format, 0);
	SDL_FreeSurface(loaded_surface);
	if (!output_surface)
		return (NULL);
	return (output_surface);
}

SDL_Surface	*wipe_surface(SDL_Surface *surface, int color)
{
	SDL_LockSurface(surface);
	SDL_memset(surface->pixels, color, surface->h * surface->pitch);
	SDL_UnlockSurface(surface);
	return (surface);
}

uint32_t	get_pixel(SDL_Surface *surface, t_vector2i pos)
{
	Uint8	*p;
	int		bpp;

	if (pos.x < 0 || pos.y < 0 || pos.x > surface->w || pos.y > surface->h)
		return (0);
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + pos.y * surface->pitch + pos.x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(Uint16 *)p);
	if (bpp == 3)
		return (p[0] | p[1] << 8 | p[2] << 16);
	if (bpp == 4)
		return (*(Uint32 *)p);
	else
		return (0);
}

void		set_pixel(SDL_Surface *surface, t_vector2i pos, uint32_t pixel)
{
	Uint8	*p;
	int		bpp;

	if (pos.x < 0 || pos.y < 0 || pos.x > surface->w || pos.y > surface->h)
		return ;
	if (SDL_MUSTLOCK(surface))
		SDL_LockSurface(surface);
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + pos.y * surface->pitch + pos.x * bpp;
	if (bpp == 1)
		*p = pixel;
	if (bpp == 2)
		*(Uint16 *)p = pixel;
	if (bpp == 3)
	{
		p[0] = pixel & 0xff;
		p[1] = (pixel >> 8) & 0xff;
		p[2] = (pixel >> 16) & 0xff;
	}
	if (bpp == 4)
		*(Uint32 *)p = pixel;
	if (SDL_MUSTLOCK(surface))
		SDL_UnlockSurface(surface);
}

void		draw_surf(SDL_Renderer *renderer, SDL_Surface *surface,
				t_vector2i pos)
{
	t_vector2i	size;
	SDL_Texture	*text;

	text = SDL_CreateTextureFromSurface(renderer, surface);
	if (!text)
		return ;
	size.x = surface->w;
	size.y = surface->h;
	SDL_RenderCopy(renderer, text, &(SDL_Rect){pos.x, pos.y, size.x, size.y},
		&(SDL_Rect){pos.x, pos.y, size.x, size.y});
	SDL_DestroyTexture(text);
}
