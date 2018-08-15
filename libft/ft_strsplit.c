/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:40:05 by mtshisw           #+#    #+#             */
/*   Updated: 2018/06/02 15:39:10 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		words_counter(char const *s, char c)
{
	int	wcount;

	wcount = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			wcount++;
			while (*s && *s != c)
				s++;
		}
	}
	return (wcount);
}

static	char	*diff_words(char const *s, char c)
{
	int		i;
	size_t	slength;
	char	*newstr;

	slength = ft_strlen(s);
	if (!(newstr = (char *)malloc(slength + 1)))
		return (NULL);
	i = 0;
	while (*s != '\0' && *s != c)
		newstr[i++] = *s++;
	newstr[i] = '\0';
	return (newstr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_wrd;
	char	**tab;

	if (!s)
		return (NULL);
	nb_wrd = words_counter(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_wrd + 1))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			tab[i] = diff_words(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
