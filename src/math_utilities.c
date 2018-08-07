/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 23:23:09 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 23:23:11 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	math_copy_matrix(float dst[4][4], float src[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] = src[i][j];
			++j;
		}
		++i;
	}
}

void	math_matrix_identity(float mat[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
			++j;
		}
		++i;
	}
}
