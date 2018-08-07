/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 02:11:40 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/30 08:10:57 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "window.h"
#include "libft.h"

int		f_exit(void)
{
	exit(1);
	return (0);
}

int		f_exit_err(int i_errno)
{
	ft_putendl(strerror(i_errno));
	f_exit();
	return (0);
}
