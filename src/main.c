/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 21:50:38 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 18:47:17 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "mlx.h"
#include "fdf.h"
#include "keys.h"
#include "libft.h"
#include "line.h"
#include "coords.h"
#include "colors.h"
#include "window.h"
#include "file_manager.h"

static void	init_cam(t_camera *cam, int width, int height, int max_y)
{
	cam->pos.x = width / 2.0;
	cam->pos.y = -1;
	cam->pos.z = (width > height ? -width / 3.0 : -height / 3.0);
	if (-max_y < (cam->pos.z / 2.0))
		cam->pos.z -= (max_y - (cam->pos.z / 2.0));
	cam->rot.x = 0;
	cam->rot.y = -45;
	cam->rot.z = 180;
}

static void	init_keys(t_game *g)
{
	int i;

	i = 0;
	while (i < 127)
		g->keys[i++] = 0;
}

static void	simple_error(char *str, int val)
{
	ft_putendl(str);
	exit(val);
}

static void	get_args(int argc, char **argv, t_game *game)
{
	int i;

	i = 2;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "color=", 6) == 0)
			game->color = ft_atoi(argv[i] + 6);
		else if (ft_strncmp(argv[i], "projection=", 12) == 0)
		{
			if (ft_strcmp(argv[i] + 12, "ortographic") == 0)
				game->per_project = 0;
			else if (ft_strcmp(argv[i] + 12, "perspective") == 0)
				game->per_project = 1;
			else
				simple_error("projection types:\nperspective\nortographic", -1);
		}
		else
			simple_error("invalid argument(s)", -1);
		++i;
	}
}

int			main(int argc, char **argv)
{
	t_game		game;
	int			max_y;

	game.color = C_WHITE;
	game.per_project = 1;
	if (argc < 2)
		simple_error("Usage: fdf file_name [color=int] \
[projection=[perspective/ortographic]]", -1);
	else
		get_args(argc, argv, &game);
	if (!get_map(argv[1], &game.width, &game.height))
		simple_error("Error: Map is invalid!", -1);
	if (!(game.v.mlx = mlx_init()))
		simple_error("Error: Cannot initialize mlx!", -1);
	init_keys(&game);
	game.grid = init_grid(argv[1], game.width, game.height);
	max_y = get_max_y(game.grid, game.width, game.height);
	init_cam(&game.cam, game.width, game.height, max_y);
	game.v.window = mlx_new_window(game.v.mlx, RES_X, RES_Y, "FdF");
	mlx_hook(game.v.window, 17, 0, &f_exit, &game.v);
	mlx_hook(game.v.window, 3, 0, &key_up, &game);
	mlx_hook(game.v.window, 2, 0, &key_down, &game);
	mlx_loop_hook(game.v.mlx, &loop_handler, &game);
	mlx_loop(game.v.mlx);
	return (0);
}
