/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 00:07:28 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/03 21:44:09 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_Q		12
# define KEY_E		14
# define KEY_UP_D	126
# define KEY_DOWN_D	125
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_Z		6
# define KEY_X		7
# define KEY_TAB	48

typedef struct	s_keys
{
	int	keys[127];
}				t_keys;

#endif
