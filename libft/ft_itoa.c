/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:59:29 by mtshisw           #+#    #+#             */
/*   Updated: 2018/06/01 15:00:16 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				len_num;
	size_t			len;

	len_num = n;
	len = 1;
	while (len_num /= 10)
		len++;
	num = n;
	if (n < 0)
	{
		num = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = num % 10 + '0';
	while (num /= 10)
		str[--len] = num % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
