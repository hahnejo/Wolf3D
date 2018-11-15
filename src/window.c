/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:54:56 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:54:58 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

t_window	*create_window(int width, int height)
{
	t_window	*w;

	w = ft_memalloc(sizeof(t_window));
	if (!w)
	{
		ft_putendl("Window cannot be created!");
		return (NULL);
	}
	w->width = width;
	w->height = height;
	w->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED, \
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (w->window == NULL)
		return (NULL);
	w->renderer = SDL_CreateRenderer(w->window, -1, SDL_RENDERER_ACCELERATED);
	if (w->renderer == NULL)
		return (NULL);
	return (w);
}

void		free_window(t_window *window)
{
	SDL_Quit();
	free(window);
}
