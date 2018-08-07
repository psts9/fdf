/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 03:59:25 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 23:00:58 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "window.h"
# include "coords.h"

# define W g->width
# define H g->height

typedef struct	s_draw_line
{
	int			delta_x;
	int			delta_y;
	int			y_inc;
	int			x_inc;
	int			d;
	int			x;
	int			y;
}				t_draw_line;

void			draw_line(t_2d *p1, t_2d *p2, int col, t_win *v);
t_2d			project(t_3d *p);
void			draw_lines(t_3d **tr_grid, t_2d **d, t_game *g, int i);

#endif
