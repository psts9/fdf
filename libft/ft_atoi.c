/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:01:52 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 22:25:17 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	neg = 0;
	num = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = 10 * num + (str[i++] - '0');
	return (neg ? -num : num);
}
