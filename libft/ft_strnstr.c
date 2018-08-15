/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:42:21 by mtshisw           #+#    #+#             */
/*   Updated: 2018/06/08 12:14:33 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t hc;
	size_t nc;

	hc = 0;
	if (*small == '\0')
		return ((char *)big);
	while (big[hc] != '\0')
	{
		nc = 0;
		while (big[hc + nc] == small[nc] && len > 0)
		{
			if (small[nc + 1] == '\0')
				return ((char *)big + hc);
			len--;
			nc++;
		}
		hc++;
	}
	return (0);
}
