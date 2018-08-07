/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 07:54:03 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 19:52:46 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include "mlx.h"
#include "fdf.h"
#include "line.h"
#include "coords.h"
#include "colors.h"
#include "matrix_math.h"
#include "project.h"
#include "libft.h"
#include "file_manager.h"

static char	**gnl_split(int fd)
{
	char	*line;
	char	**result;

	if (get_next_line(fd, &line) < 0)
		f_exit_err(errno);
	result = ft_strsplit(line, ' ');
	free(line);
	return (result);
}

t_3d		**init_grid(char *filename, int width, int height)
{
	int		i;
	int		j;
	int		fd;
	char	**split_line;
	t_3d	**result;

	(!(result = malloc(height * sizeof(t_3d*))) ? f_exit_err(errno) : 0);
	((fd = open(filename, O_RDONLY)) <= 2 ? f_exit_err(errno) : 0);
	i = -1;
	while (++i < height)
	{
		j = -1;
		(!(result[i] = malloc(width * sizeof(t_3d))) ? f_exit_err(errno) : 0);
		split_line = gnl_split(fd);
		while (++j < width)
		{
			result[i][j].x = (width / 2) - j;
			result[i][j].z = (height / 2) - i;
			result[i][j].y = ft_atoi(split_line[j]) / 2.0;
			free(split_line[j]);
		}
		free(split_line);
	}
	return (result);
}

static t_3d	**transform_grid(t_3d **grid, int w, int h, t_camera *cam)
{
	int		i;
	int		j;
	t_3d	temp;
	t_3d	**result;
	float	matrix[4][4];

	if (!(result = malloc(h * sizeof(t_3d*))))
		f_exit_err(errno);
	i = -1;
	while (++i < h)
	{
		j = -1;
		if (!(result[i] = malloc(w * sizeof(t_3d))))
			f_exit_err(errno);
		while (++j < w)
		{
			result[i][j] = grid[i][j];
			temp = grid[i][j];
			math_matrix_identity(matrix);
			math_matrix_translate(matrix, -cam->pos.x, cam->pos.y, -cam->pos.z);
			math_matrix_rotate(matrix, -cam->rot.x, -cam->rot.y, -cam->rot.z);
			math_mul_vec_matrix(&result[i][j], &temp, matrix);
		}
	}
	return (result);
}

static t_2d	**project_grid(int width, int height, t_3d **gr, int b)
{
	int		i;
	int		j;
	t_2d	**ret;

	if (!(ret = malloc((height + 1) * sizeof(t_2d*))))
		f_exit_err(errno);
	i = 0;
	while (i < height)
	{
		j = 0;
		if (!(ret[i] = malloc((width + 1) * sizeof(t_2d))))
			f_exit_err(errno);
		while (j < width)
		{
			ret[i][j] = (b ? project_per(&gr[i][j]) : project_orto(&gr[i][j]));
			++j;
		}
		++i;
	}
	return (ret);
}

void		draw_grid(t_game *g, int c)
{
	int		i;
	int		j;
	t_2d	**d;
	t_3d	**trans_grid;

	trans_grid = transform_grid(g->grid, W, H, &g->cam);
	d = project_grid(W, H, trans_grid, g->per_project);
	i = -1;
	while (++i < H - 1)
		draw_lines(trans_grid, d, g, i);
	j = 0;
	while (j++ < W - 1)
	{
		if (trans_grid[H - 1][j - 1].z >= 0.1 && trans_grid[H - 1][j].z >= 0.1)
			draw_line(&d[H - 1][j - 1], &d[H - 1][j], c, &g->v);
	}
	free_arr((void***)&d, H);
	free_arr((void***)&trans_grid, H);
}
