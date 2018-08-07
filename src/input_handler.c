/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 00:38:15 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 21:49:06 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "window.h"
#include "keys.h"
#include "fdf.h"
#include "colors.h"

int			input_handler(int keycode, t_game *v)
{
	if (keycode == KEY_ESC)
	{
		v = NULL;
		f_exit();
	}
	return (0);
}

int			key_up(int keycode, t_game *g)
{
	g->keys[keycode] = 0;
	return (1);
}

int			key_down(int keycode, t_game *g)
{
	g->keys[keycode] = 1;
	return (1);
}

static void	do_key(t_game *g, int *mov, int *spin, int i)
{
	if (i == KEY_ESC)
		f_exit();
	if (*mov == 1)
		move_cam(i, g);
	else
	{
		if (i == KEY_TAB)
		{
			*spin = -(*spin);
			g->keys[i] = 0;
		}
	}
	if (i == KEY_E)
	{
		*mov = -(*mov);
		*spin = -1;
		g->keys[i] = 0;
	}
}

int			loop_handler(t_game *g)
{
	int			i;
	static int	spin = -1;
	static int	movement = -1;

	i = 0;
	while (i < 127)
	{
		if (g->keys[i] == 1)
			do_key(g, &movement, &spin, i);
		++i;
	}
	if (spin == 1)
		g->cam.rot.x += 0.5;
	mlx_clear_window(g->v.mlx, g->v.window);
	draw_grid(g, g->color);
	return (1);
}
