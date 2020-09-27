/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:21:16 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/27 18:34:11 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*filler;
	char		*line;

	line = NULL;
	if (!(filler = (t_filler *)malloc(sizeof(t_filler))))
		return (1);
	if (init_filler(filler) || parse_players(filler, &line) ||
			read_output(filler, &line))
	{
		free_plateau(filler->plateau);
		free_piece(filler->piece);
		free(filler);
		filler = NULL;
		return (1);
	}
	free_plateau(filler->plateau);
	free_piece(filler->piece);
	free(filler);
	filler = NULL;
	return (0);
}
