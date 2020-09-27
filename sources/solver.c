/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:56:54 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/23 16:52:35 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	count_sum(t_plateau *plat, t_piece *piece, int y, int x)
{
	int		i;
	int		j;
	int		sum;
	int		me_count;

	if (y + piece->height > plat->height || x + piece->width > plat->width)
		return (-1);
	sum = 0;
	me_count = 0;
	j = -1;
	while (++j < piece->height)
	{
		i = -1;
		while (++i < piece->width)
			if (piece->map[j][i] == '*')
			{
				if (plat->map[y + j][x + i] == ENEMY)
					return (-1);
				else if (plat->map[y + j][x + i] == ME)
					me_count++;
				else
					sum += plat->map[y + j][x + i];
			}
	}
	return ((me_count == 1) ? sum : -1);
}

void		finde_place(t_filler *filler, t_plateau *plateau, t_piece *piece)
{
	int		x;
	int		y;
	int		sum;
	int		min_sum;

	min_sum = MAXINT;
	y = 0;
	while (y < filler->plateau->height)
	{
		x = 0;
		while (x < filler->plateau->width)
		{
			sum = count_sum(plateau, piece, y, x);
			if (sum != -1 && sum < min_sum)
			{
				filler->y = y;
				filler->x = x;
				min_sum = sum;
			}
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", filler->y, filler->x);
	zero_coords(filler);
}

int			read_output(t_filler *filler, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (ft_strncmp(*line, "Plateau", 7) == 0)
		{
			if (!filler->plateau->map)
				if (create_plateau(filler, ft_strsplitstr(*line, " ")))
					return (1);
			get_plateau(filler, *line);
			heat_map(filler->plateau);
		}
		else if (ft_strncmp(*line, "Piece", 5) == 0)
		{
			if (create_piece(filler, ft_strsplitstr(*line, " ")))
			{
				ft_strdel(line);
				return (1);
			}
			get_piece(filler, *line);
			finde_place(filler, filler->plateau, filler->piece);
		}
		else
			ft_strdel(line);
	}
	return (0);
}
