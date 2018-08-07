/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 03:47:39 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/02 21:01:13 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx.h"
#include "window.h"
#include "line.h"
#include "coords.h"
#include "fdf.h"
#include "libft.h"
#include "colors.h"

static void	draw_line_low(t_2d *p1, t_2d *p2, int col, t_win *v)
{
	t_draw_line	line;

	line.delta_x = p2->x - p1->x;
	line.delta_y = p2->y - p1->y;
	line.y_inc = 1;
	if (line.delta_y < 0)
	{
		line.y_inc = -1;
		line.delta_y = -(line.delta_y);
	}
	line.d = 2 * line.delta_y - line.delta_x;
	line.x = p1->x;
	line.y = p1->y;
	while (line.x <= p2->x && line.x < RES_X)
	{
		mlx_pixel_put(v->mlx, v->window, line.x, line.y, (int)col);
		if (line.d > 0)
		{
			line.y += line.y_inc;
			line.d -= 2 * line.delta_x;
		}
		line.d += 2 * line.delta_y;
		++line.x;
	}
}

static void	draw_line_high(t_2d *p1, t_2d *p2, int col, t_win *v)
{
	t_draw_line	line;

	line.delta_x = p2->x - p1->x;
	line.delta_y = p2->y - p1->y;
	line.x_inc = 1;
	if (line.delta_x < 0)
	{
		line.x_inc = -1;
		line.delta_x = -(line.delta_x);
	}
	line.d = 2 * line.delta_x - line.delta_y;
	line.x = p1->x;
	line.y = p1->y;
	while (line.y <= p2->y && line.y < RES_Y)
	{
		mlx_pixel_put(v->mlx, v->window, line.x, line.y, (int)col);
		if (line.d > 0)
		{
			line.x += line.x_inc;
			line.d -= 2 * line.delta_y;
		}
		line.d += 2 * line.delta_x;
		++line.y;
	}
}

void		draw_lines(t_3d **tr_grid, t_2d **d, t_game *g, int i)
{
	int j;

	j = -1;
	while (++j < W - 1)
	{
		if (tr_grid[i][j].z >= 0.1 && tr_grid[i][j + 1].z >= 0.1)
			draw_line(&d[i][j], &d[i][j + 1], g->color, &g->v);
		if (tr_grid[i][j].z >= 0.1 && tr_grid[i + 1][j].z >= 0.1)
			draw_line(&d[i][j], &d[i + 1][j], g->color, &g->v);
	}
	if (tr_grid[i][W - 1].z >= 0.1 && tr_grid[i + 1][W - 1].z >= 0.1)
		draw_line(&d[i][W - 1], &d[i + 1][W - 1], g->color, &g->v);
}

void		draw_line(t_2d *p1, t_2d *p2, int col, t_win *v)
{
	int abs_x;
	int abs_y;

	abs_x = p2->x - p1->x;
	abs_y = p2->y - p1->y;
	if (abs_x < 0)
		abs_x = -abs_x;
	if (abs_y < 0)
		abs_y = -abs_y;
	if (abs_y < abs_x)
	{
		if (p1->x > p2->x)
			draw_line_low(p2, p1, col, v);
		else
			draw_line_low(p1, p2, col, v);
	}
	else
	{
		if (p1->y > p2->y)
			draw_line_high(p2, p1, col, v);
		else
			draw_line_high(p1, p2, col, v);
	}
}
