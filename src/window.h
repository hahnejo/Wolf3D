/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:58:18 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 00:58:19 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WINDOW_H
# define WOLF3D_WINDOW_H
# include <SDL.h>
# include <SDL_image.h>
# include "libft.h"

typedef struct		s_window
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				width;
	int				height;
}					t_window;

t_window			*create_window(int width, int height);
SDL_Texture			*load_texture(char *filename, SDL_Renderer *renderer);
void				free_window(t_window *window);

#endif
