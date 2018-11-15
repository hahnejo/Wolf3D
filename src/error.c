/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:17:20 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:17:22 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

static int	check_content(char *text)
{
	int i;

	i = 0;
	while (text[i])
	{
		if (!ft_isdigit(text[i]) && text[i] != ' ' && text[i] != '\n')
		{
			ft_putendl("Your map file has other value than 0 - 9 or space");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_space(char *text)
{
	int i;

	i = 0;
	while (text[i])
	{
		if ((i == 0 || text[i - 1] == '\n') && !ft_isdigit(text[i]))
		{
			ft_putendl("Your map has invalid spacing");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_special_row(char *text)
{
	int count;
	int first_row;
	int i;

	i = -1;
	count = 1;
	first_row = -1;
	while (text[++i])
	{
		if (text[i] == ' ')
		{
			count++;
			if (text[i + 1] == ' ')
				return (-1);
		}
		if (text[i] == '\n')
		{
			if (first_row == -1)
				first_row = count;
			if (count != first_row)
				return (-1);
			count = 1;
		}
	}
	return (0);
}

int			check_three_by_three(char *text)
{
	int i;
	int row;
	int column;
	int newline;

	newline = 0;
	i = 0;
	row = 0;
	column = 1;
	while (text[i])
	{
		if (text[i] == ' ' && !newline)
			column++;
		if (text[i] == '\n')
		{
			newline = 1;
			row++;
		}
		i++;
	}
	if (row < 3 || column < 3)
		return (-1);
	else
		return (0);
}

int			validate_map(char *text)
{
	if (check_content(text) != 0)
		return (-1);
	if (check_space(text) != 0)
		return (-1);
	if (check_special_row(text) != 0)
		return (-1);
	if (check_three_by_three(text) != 0)
		return (-1);
	return (0);
}
