/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 22:58:17 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/04 22:58:33 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

int		get_map(char *filename, int *width, int *height);
void	free_arr(void ***grid, int size);

#endif
