/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:46:58 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/23 16:53:13 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece_map(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->height)
	{
		free(piece->map[i]);
		i++;
	}
	free(piece->map);
}

int		create_piece(t_filler *filler, char **str)
{
	int		i;

	i = 0;
	if (filler->piece->map)
		free_piece_map(filler->piece);
	filler->piece->height = ft_atoi(str[1]);
	filler->piece->width = ft_atoi(str[2]);
	if (!(filler->piece->map = (char **)malloc(sizeof(char *) *
		filler->piece->height)))
		return (1);
	while (i < filler->piece->height)
	{
		if (!(filler->piece->map[i] = (char *)malloc(sizeof(char) *
			filler->piece->width)))
			return (1);
		i++;
	}
	free(str);
	return (0);
}

int		get_piece(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	ft_strdel(&line);
	while (i < filler->piece->height)
	{
		if (!(get_next_line(0, &line)))
			return (1);
		write_in_piece_map(filler, line, i);
		ft_strdel(&line);
		i++;
	}
	return (0);
}

void	write_in_piece_map(t_filler *filler, char *line, int num_str)
{
	int		i;

	i = 0;
	while (i < filler->piece->width)
	{
		if (line[i] == '.')
			filler->piece->map[num_str][i] = '.';
		else if (line[i] == '*')
			filler->piece->map[num_str][i] = '*';
		i++;
	}
}
