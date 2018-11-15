/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 02:01:08 by astrole           #+#    #+#             */
/*   Updated: 2018/11/14 02:01:10 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "error.h"
#include "game_io.h"

static void	check_width_height(char *str, t_grid *map)
{
	int i;
	int width;
	int height;
	int newline;

	i = 0;
	height = 0;
	newline = 0;
	width = 1;
	while (str[i])
	{
		if (str[i] == ' ' && newline == 0)
			width++;
		if (str[i] == '\n')
		{
			newline = 1;
			height++;
		}
		i++;
	}
	map->grid_width = width;
	map->grid_height = height;
}

static int	malloc_grid(t_grid *map)
{
	int	i;
	int j;

	map->grid = ft_memalloc(sizeof(int*) * map->grid_height);
	if (!map->grid)
		return (-1);
	i = -1;
	while (++i < map->grid_height)
	{
		j = 0;
		map->grid[i] = ft_memalloc(sizeof(int) * map->grid_width);
		if (!map->grid[i])
			return (-1);
		while (j < map->grid_width)
			map->grid[i][j++] = 1;
	}
	return (0);
}

static void	save_numbers(char *str, t_grid *map)
{
	int		i;
	int		j;
	int		k;
	char	**lines;
	char	**new_line;

	new_line = ft_strsplit(str, '\n');
	i = -1;
	while (new_line[++i])
	{
		j = -1;
		lines = ft_strsplit(new_line[i], ' ');
		while (lines[++j])
			map->grid[i][j] = ft_atoi(lines[j]);
		k = 0;
		while (lines[k])
			free(lines[k++]);
		free(lines);
	}
	i = 0;
	while (new_line[i])
		free(new_line[i++]);
	free(new_line);
}

t_grid		*new_grid(char *filename)
{
	char	*text;
	t_grid	*grid;
	char	**names;

	text = read_file(filename);
	if (!text || validate_map(text) == -1)
		return (NULL);
	grid = ft_memalloc(sizeof(t_grid));
	check_width_height(text, grid);
	if (malloc_grid(grid) == -1)
		return (NULL);
	save_numbers(text, grid);
	free(text);
	if (!check_full_map(grid))
		return (NULL);
	names = get_image_names("images");
	if (!names)
		return (NULL);
	grid->images = load_map_images(names);
	if (!grid->images)
		return (NULL);
	while (grid->images[grid->images_length])
		free(names[grid->images_length++]);
	free(names);
	return (grid);
}

void		free_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->images_length)
	{
		SDL_FreeSurface(grid->images[i]);
		i++;
	}
	i = 0;
	while (i < grid->grid_height)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
	free(grid->images);
	free(grid);
}
