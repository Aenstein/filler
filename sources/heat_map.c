/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:45:07 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/19 18:00:57 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	manhattan(int x, int y, int i, int j)
{
	int		a;
	int		b;

	if (i > x)
		a = i - x;
	else
		a = x - i;
	if (j > y)
		b = j - y;
	else
		b = y - j;
	return (a + b);
}

static int	calc_distance(t_plateau *plateau, int x, int y)
{
	int		i;
	int		j;
	int		dist;
	int		min_dist;

	min_dist = MAXINT;
	j = 0;
	while (j < plateau->height)
	{
		i = 0;
		while (i < plateau->width)
		{
			if (plateau->map[j][i] == ENEMY)
			{
				dist = manhattan(x, y, i, j);
				if (dist < min_dist)
					min_dist = dist;
			}
			i++;
		}
		j++;
	}
	return (min_dist);
}

void		heat_map(t_plateau *plateau)
{
	int		x;
	int		y;

	y = 0;
	while (y < plateau->height)
	{
		x = 0;
		while (x < plateau->width)
		{
			if (plateau->map[y][x] == EMPTY)
				plateau->map[y][x] = calc_distance(plateau, x, y);
			x++;
		}
		y++;
	}
}
