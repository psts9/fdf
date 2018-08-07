/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 22:39:47 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 22:39:57 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "window.h"
#include "fdf.h"

#define BUFF_SIZE 4096
#define ABS(x) ((x < 0) ? -x : x)

void		free_arr(void ***grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*grid)[i]);
		++i;
	}
	free(*grid);
}

int			get_max_y(t_3d **grid, int width, int height)
{
	int	i;
	int	j;
	int	max_y;

	i = 0;
	max_y = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (ABS(grid[i][j].y) > max_y)
				max_y = ABS(grid[i][j].y);
			++j;
		}
		++i;
	}
	return (max_y);
}

static char	*file_to_str(char *filename)
{
	int		fd;
	int		rd;
	char	buf[BUFF_SIZE];
	char	*result;

	rd = 0;
	if ((fd = open(filename, O_RDONLY)) <= 0)
		f_exit_err(errno);
	result = ft_strnew(0);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		free_strjoin(&result, buf);
	}
	if (rd < 0)
		f_exit_err(errno);
	close(fd);
	return (result);
}

static int	get_map_helper(int *width, int *height, char *str, int *prev_width)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i] != '\n')
		{
			++(*width);
			while (str[i] && str[i] != '\n' && str[i] != ' ')
				++i;
		}
		else
		{
			++(*height);
			if (*prev_width && *width != *prev_width)
				return (0);
			*prev_width = *width;
			*width = 0;
			++i;
		}
	}
	(str[i - 1] != '\n' ? --(*height) : 0);
	return (1);
}

int			get_map(char *filename, int *width, int *height)
{
	char	*str;
	int		i;
	int		prev_width;

	*width = 0;
	*height = 0;
	prev_width = 0;
	i = 0;
	str = file_to_str(filename);
	if (!get_map_helper(width, height, str, &prev_width))
		return (0);
	*width = prev_width;
	if (*width == 0 || *height == 0)
		return (0);
	free(str);
	return (1);
}
