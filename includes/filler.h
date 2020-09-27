/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:13:30 by aenstein          #+#    #+#             */
/*   Updated: 2020/09/23 16:47:38 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../lib/includes/header.h"
# include "../lib/libft/libft.h"
# define EMPTY	0
# define ME		-1
# define ENEMY	-2
# define MAXINT	2147483647

typedef struct	s_plateau
{
	int			height;
	int			width;
	int			**map;
}				t_plateau;

typedef struct	s_piece
{
	int			height;
	int			width;
	char		**map;
}				t_piece;

typedef struct	s_filler
{
	char		me;
	char		enemy;
	int			x;
	int			y;
	t_piece		*piece;
	t_plateau	*plateau;
}				t_filler;

int				parse_players(t_filler *filler, char **line);
int				read_output(t_filler *filler, char **line);
int				get_plateau(t_filler *filler, char *line);
int				create_plateau(t_filler *filler, char **str);
int				get_piece(t_filler *filler, char *line);
int				create_piece(t_filler *filler, char **str);
void			write_in_piece_map(t_filler *filler, char *line, int num_str);
void			free_strsplit(char **str);
void			heat_map(t_plateau *plateau);
int				init_filler(t_filler *filler);
void			zero_coords(t_filler *filler);
void			free_plateau(t_plateau *plateau);
void			free_piece(t_piece *piece);
#endif
