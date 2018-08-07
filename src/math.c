/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:33:08 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 14:59:49 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "coords.h"
#include "matrix_math.h"

#define D_COS(x) cos(x * M_PI / 180)
#define D_SIN(x) sin(x * M_PI / 180)

void	math_mul_matrix(float dst[4][4], float m1[4][4], float m2[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] = m1[i][0] * m2[0][j] +
						m1[i][1] * m2[1][j] +
						m1[i][2] * m2[2][j] +
						m1[i][3] * m2[3][j];
			++j;
		}
		++i;
	}
}

void	math_mul_vec_matrix(t_3d *dst, t_3d *src, float mat[4][4])
{
	dst->x =
		src->x * mat[0][0] +
		src->y * mat[1][0] +
		src->z * mat[2][0] +
		mat[3][0];
	dst->y =
		src->x * mat[0][1] +
		src->y * mat[1][1] +
		src->z * mat[2][1] +
		mat[3][1];
	dst->z =
		src->x * mat[0][2] +
		src->y * mat[1][2] +
		src->z * mat[2][2] +
		mat[3][2];
}

void	math_matrix_translate(float mat[4][4], float tx, float ty, float tz)
{
	float	tmat[4][4];
	float	tmp[4][4];

	math_matrix_identity(tmat);
	tmat[3][0] = tx;
	tmat[3][1] = ty;
	tmat[3][2] = tz;
	math_mul_matrix(tmp, mat, tmat);
	math_copy_matrix(mat, tmp);
}

void	math_matrix_scale(float mat[4][4], float sx, float sy, float sz)
{
	float	smat[4][4];
	float	tmp[4][4];

	math_matrix_identity(smat);
	smat[0][0] = sx;
	smat[1][1] = sy;
	smat[2][2] = sz;
	math_mul_matrix(tmp, mat, smat);
	math_copy_matrix(mat, tmp);
}

void	math_matrix_rotate(float mat[4][4], int ax, int ay, int az)
{
	float xmat[4][4];
	float ymat[4][4];
	float zmat[4][4];
	float tmp1[4][4];
	float tmp2[4][4];

	math_matrix_identity(xmat);
	math_matrix_identity(ymat);
	math_matrix_identity(zmat);
	xmat[1][1] = D_COS(ax);
	xmat[1][2] = D_SIN(ax);
	xmat[2][1] = -D_SIN(ax);
	xmat[2][2] = D_COS(ax);
	ymat[0][0] = D_COS(ay);
	ymat[0][2] = -D_SIN(ay);
	ymat[2][0] = D_SIN(ay);
	ymat[2][2] = D_COS(ay);
	zmat[0][0] = D_COS(az);
	zmat[0][1] = D_SIN(az);
	zmat[1][0] = -D_SIN(az);
	zmat[1][1] = D_COS(az);
	math_mul_matrix(tmp1, mat, ymat);
	math_mul_matrix(tmp2, xmat, tmp1);
	math_mul_matrix(mat, tmp2, zmat);
}
