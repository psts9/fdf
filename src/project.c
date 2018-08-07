/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:11:11 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 19:34:54 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "coords.h"
#include "fdf.h"

t_2d	project_per(t_3d *p)
{
	t_2d result;

	if (!p->z)
		p->z = 1;
	result.x = (int)(FOCAL_DISTANCE * p->x / p->z + RES_X / 2);
	result.y = (int)(FOCAL_DISTANCE * p->y / p->z + RES_Y / 2);
	return (result);
}

t_2d	project_orto(t_3d *p)
{
	t_2d	result;

	result.x = FOCAL_DISTANCE / 4 * p->x + RES_X / 2;
	result.y = FOCAL_DISTANCE / 4 * p->y + RES_Y / 2;
	return (result);
}
