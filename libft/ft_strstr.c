/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:23:54 by mtshisw           #+#    #+#             */
/*   Updated: 2018/05/28 18:24:05 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t hc;
	size_t nc;

	hc = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[hc] != '\0')
	{
		nc = 0;
		while (haystack[hc + nc] == needle[nc])
		{
			if (needle[nc + 1] == '\0')
				return ((char *)haystack + hc);
			nc++;
		}
		hc++;
	}
	return (0);
}
