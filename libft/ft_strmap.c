/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:50:09 by mtshisw           #+#    #+#             */
/*   Updated: 2018/05/30 11:28:42 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fstr;

	i = 0;
	if (!s)
		return (NULL);
	fstr = (char *)malloc(ft_strlen(s) + 1);
	if (!fstr)
		return (NULL);
	while (*s)
	{
		fstr[i] = (*f)(*s);
		i++;
		s++;
	}
	fstr[i] = '\0';
	return (fstr);
}
