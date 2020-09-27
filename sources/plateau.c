/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:09:05 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/23 16:52:59 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	write_in_plat_map(t_filler *filler, char *line, int num_str)
{
	int		i;

	i = 0;
	while ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
		i++;
	while (i < (filler->plateau->width + 4))
	{
		if (line[i] == '.')
			filler->plateau->map[num_str][i - 4] = EMPTY;
		else if (ft_toupper(line[i]) == filler->me)
			filler->plateau->map[num_str][i - 4] = ME;
		else if (ft_toupper(line[i]) == filler->enemy)
			filler->plateau->map[num_str][i - 4] = ENEMY;
		i++;
	}
}

int			create_plateau(t_filler *filler, char **str)
{
	int		i;

	i = 0;
	filler->plateau->height = ft_atoi(str[1]);
	filler->plateau->width = ft_atoi(str[2]);
	if (!(filler->plateau->map = (int **)malloc(sizeof(int *) *
		filler->plateau->height)))
		return (1);
	while (i < filler->plateau->height)
	{
		if (!(filler->plateau->map[i] = (int *)malloc(sizeof(int) *
			filler->plateau->width)))
			return (1);
		i++;
	}
	free(str);
	return (0);
}

int			get_plateau(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < filler->plateau->height)
	{
		if (!(get_next_line(0, &line)))
			return (-1);
		write_in_plat_map(filler, line, i);
		ft_strdel(&line);
		i++;
	}
	return (0);
}
