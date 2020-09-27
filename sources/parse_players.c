/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:04:13 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/27 18:34:22 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	valid_player(char **str)
{
	if (ft_strcmp(str[0], "$$$") || ft_strcmp(str[1], "exec") ||
		(ft_strcmp(str[2], "p1") && ft_strcmp(str[2], "p2")) ||
		ft_strcmp(str[3], ":") || str[4][0] != '[' ||
		!ft_strstr(str[4], "aenstein.filler]"))
		return (1);
	return (0);
}

int			parse_players(t_filler *filler, char **line)
{
	char	**str;

	str = NULL;
	if (!(get_next_line(0, line)))
		return (1);
	str = ft_strsplitstr(*line, " ");
	if (!(str))
		return (1);
	if (valid_player(str))
	{
		ft_strdel(line);
		free(str);
		return (1);
	}
	filler->me = (!(ft_strcmp(str[2], "p1"))) ? 'O' : 'X';
	filler->enemy = (!(ft_strcmp(str[2], "p1"))) ? 'X' : 'O';
	ft_strdel(line);
	free(str);
	return (0);
}
