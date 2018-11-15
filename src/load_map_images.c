/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:48:00 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 00:48:02 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "surface.h"
#include "libft.h"
#include "game_io.h"

SDL_Surface		**load_map_images(char **names)
{
	int			i;
	SDL_Surface	**images;

	i = 0;
	while (names[i])
		i++;
	images = ft_memalloc(sizeof(SDL_Surface**) * (i + 1));
	if (!images)
		return (NULL);
	i = 0;
	while (names[i])
	{
		images[i] = load_image_surface(names[i]);
		if (!images[i])
			return (NULL);
		i++;
	}
	return (images);
}

char			**get_image_names(char *filename)
{
	char *text;
	char **lines;

	text = read_file(filename);
	if (!text)
		return (NULL);
	lines = ft_strsplit(text, '\n');
	free(text);
	return (lines);
}
