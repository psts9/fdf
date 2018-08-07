/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 00:14:27 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 21:32:12 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "coords.h"

typedef struct	s_win
{
	void		*mlx;
	void		*window;
}				t_win;

typedef struct	s_game
{
	t_win		v;
	t_camera	cam;
	t_3d		**grid;
	int			width;
	int			height;
	int			keys[127];
	int			color;
	int			per_project;
}				t_game;

#endif
