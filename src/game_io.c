/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:13:52 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:13:54 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

char	*read_file(char *filename)
{
	char	*line;
	char	*str;
	char	*temp;
	char	*old_str;
	int		fd;

	fd = open(filename, O_RDONLY);
	str = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		temp = ft_strjoin(line, "\n");
		old_str = str;
		if (str != NULL)
			str = ft_strjoin(str, temp);
		else
			str = ft_strdup(temp);
		if (old_str)
			free(old_str);
		free(line);
		free(temp);
	}
	return (str);
}
