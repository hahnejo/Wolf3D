/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:14:45 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:14:50 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int		calc_frame(void)
{
	static int	start = 0;
	static int	frames = 0;
	int			current;
	int			temp;

	if (start == 0)
		start = SDL_GetTicks();
	current = SDL_GetTicks();
	if ((current - start) >= 1000)
	{
		start = SDL_GetTicks();
		temp = frames;
		frames = 0;
		return (temp);
	}
	frames++;
	return (-1);
}

void	limit_frame(int fps, int start)
{
	int end;
	int ticks;
	int diff;

	end = SDL_GetTicks();
	ticks = 1000 / fps;
	diff = end - start;
	if (diff < ticks)
		SDL_Delay(ticks - diff);
}
