/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:09:25 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 21:09:28 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "window.h"
#include "keys.h"
#include "fdf.h"

void	move_cam(int keycode, t_game *g)
{
	int		f;

	if (keycode == KEY_X || keycode == KEY_Z)
		g->cam.pos.y += (keycode == KEY_X ? MOV_SPEED : -MOV_SPEED);
	else if (keycode == KEY_W || keycode == KEY_S)
	{
		f = (keycode == KEY_W ? 1 : -1);
		g->cam.pos.z += f * MOV_SPEED * cos(g->cam.rot.y * M_PI / 180);
		g->cam.pos.x += f * MOV_SPEED * sin(g->cam.rot.y * M_PI / 180);
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		f = (keycode == KEY_D ? 1 : -1);
		g->cam.pos.z += f * MOV_SPEED * cos((g->cam.rot.y - 90) * M_PI / 180);
		g->cam.pos.x += f * MOV_SPEED * sin((g->cam.rot.y - 90) * M_PI / 180);
	}
	else if (keycode == KEY_UP_D || keycode == KEY_DOWN_D)
		g->cam.rot.x += (keycode == KEY_DOWN_D ? TURN_SPEED : -TURN_SPEED);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		g->cam.rot.y += (keycode == KEY_RIGHT ? -TURN_SPEED : TURN_SPEED);
}
