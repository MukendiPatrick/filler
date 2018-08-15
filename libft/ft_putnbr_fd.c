/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:21:46 by mtshisw           #+#    #+#             */
/*   Updated: 2018/06/01 16:52:45 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -1 * num;
	}
	if (num >= 0 && num <= 9)
		ft_putchar_fd((num + '0'), fd);
	else if (num >= 10)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putchar_fd(((num % 10) + '0'), fd);
	}
}
