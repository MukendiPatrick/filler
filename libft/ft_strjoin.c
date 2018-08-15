/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:30:20 by mtshisw           #+#    #+#             */
/*   Updated: 2018/05/30 16:06:49 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*cat;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cat)
		return (NULL);
	while (*s1)
		cat[i++] = *s1++;
	while (*s2)
		cat[i++] = *s2++;
	cat[i] = '\0';
	return (cat);
}
