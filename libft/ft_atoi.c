/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:50:56 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:12:50 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	long long	num;
	long		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-' ? -1 : 1);
	while (ft_isdigit(str[i]))
	{
		if (num == 2147483648 && sign == -1)
			return (-2147483648);
		if (num > 2147483647)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		num = (num * 10) + str[i++] - '0';
	}
	return (sign * num);
}
