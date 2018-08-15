/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:17:12 by mtshisw           #+#    #+#             */
/*   Updated: 2018/06/01 16:21:20 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	ssizepl;
	unsigned int	sndsize;
	int				dlen;

	ssizepl = ft_strlen(src) + dstsize;
	sndsize = ft_strlen(src) + ft_strlen(dest);
	if (ssizepl <= sndsize)
		return (ssizepl);
	ssizepl -= sndsize + 1;
	dlen = ft_strlen(dest);
	while (ssizepl > 0 && *src != '\0')
	{
		dest[dlen++] = *src++;
		ssizepl--;
	}
	dest[dlen] = '\0';
	return (sndsize);
}
