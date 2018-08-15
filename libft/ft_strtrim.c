/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:51:08 by mtshisw           #+#    #+#             */
/*   Updated: 2018/06/04 14:58:10 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (s)
	{
		i = 0;
		len = ft_strlen((char *)(s)) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		if ((len - i) <= 0)
			return (ft_strdup(""));
		str = (char *)malloc(sizeof(*str) * (len - i + 2));
		if (!str)
			return (NULL);
		j = 0;
		while (i <= len)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
