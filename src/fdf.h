/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 01:15:41 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 22:38:32 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "window.h"
# include "coords.h"

# define FOCAL_DISTANCE 200
# define RES_X 1920
# define RES_Y 1080

# define MOV_SPEED 0.1
# define TURN_SPEED 1.0

int		input_handler(int keycode, t_game *v);
int		f_exit(void);
int		f_exit_err(int i_errno);
void	draw_grid(t_game *g, int color);
t_3d	**init_grid(char *filename, int width, int height);
void	move_cam(int keycode, t_game *g);
int		loop_handler(t_game *g);
int		key_up(int keycode, t_game *g);
int		key_down(int keycode, t_game *g);
int		get_max_y(t_3d **grid, int width, int height);
void	move_cam(int keycode, t_game *g);

#endif
