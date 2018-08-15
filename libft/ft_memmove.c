/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:06:11 by mtshisw           #+#    #+#             */
/*   Updated: 2018/05/29 14:35:11 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	else
	{
		while (len)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
		return (dest);
	}
}
