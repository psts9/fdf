/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:03:22 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/01 14:40:33 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_MATH_H
# define MATRIX_MATH_H

void	math_copy_matrix(float dst[4][4], float src[4][4]);
void	math_mul_matrix(float dst[4][4], float m1[4][4], float m2[4][4]);
void	math_mul_vec_matrix(t_3d *dst, t_3d *src, float mat[4][4]);
void	math_matrix_identity(float mat[4][4]);
void	math_matrix_translate(float mat[4][4], float tx, float ty, float tz);
void	math_matrix_scale(float mat[4][4], float sx, float sy, float sz);
void	math_matrix_rotate(float mat[4][4], int ax, int ay, int az);

#endif
