/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:28:23 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:28:26 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_wolf *wolf;

	if (argc == 2)
	{
		wolf = create_wolf(argv[1]);
		if (!wolf)
			return (-1);
		run_wolf(wolf);
	}
	else
	{
		ft_putendl("Please enter only one valid file");
		return (1);
	}
	free_wolf(wolf);
	return (0);
}
