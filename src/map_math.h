/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:34:19 by hjo               #+#    #+#             */
/*   Updated: 2018/11/10 01:34:20 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MAP_MATH_H
# define WOLF3D_MAP_MATH_H
# include "vector.h"
# include "map.h"

double				map(double n, t_vector2f range1, t_vector2f range2);
double				map_constrain(double n, t_vector2f range1,
	t_vector2f range2);
double				constrain(double n, double low, double high);

#endif
