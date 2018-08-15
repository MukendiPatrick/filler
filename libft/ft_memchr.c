/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:40:09 by mtshisw           #+#    #+#             */
/*   Updated: 2018/05/29 15:11:02 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char *str;
	unsigned char ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (len > 0)
	{
		if (*str == ch)
			return ((unsigned char *)str);
		str++;
		len--;
	}
	return (NULL);
}
