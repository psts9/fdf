/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:54:47 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 20:50:31 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDS_H
# define COORDS_H

typedef struct	s_2d
{
	int			x;
	int			y;
}				t_2d;

typedef struct	s_3d
{
	float		x;
	float		y;
	float		z;
}				t_3d;

typedef struct	s_camera
{
	t_3d		pos;
	t_3d		rot;
}				t_camera;

#endif
