/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free_fun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:14:11 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/19 18:01:02 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_filler(t_filler *filler)
{
	t_plateau	*plateau;
	t_piece		*piece;

	if (!(plateau = (t_plateau *)malloc(sizeof(t_plateau))))
		return (1);
	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (1);
	plateau->height = 0;
	plateau->width = 0;
	plateau->map = NULL;
	filler->plateau = plateau;
	piece->height = 0;
	piece->width = 0;
	piece->map = NULL;
	filler->piece = piece;
	filler->me = 0;
	filler->enemy = 0;
	filler->x = 0;
	filler->y = 0;
	return (0);
}

void		free_strsplit(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void		free_plateau(t_plateau *plateau)
{
	int i;

	i = 0;
	while (i < plateau->height)
	{
		free(plateau->map[i]);
		i++;
	}
	free(plateau->map);
	free(plateau);
	plateau = NULL;
}

void		free_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->height)
	{
		free(piece->map[i]);
		i++;
	}
	free(piece->map);
	free(piece);
	piece = NULL;
}

void		zero_coords(t_filler *filler)
{
	filler->x = 0;
	filler->y = 0;
}
