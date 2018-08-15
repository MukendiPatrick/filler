/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:58:59 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/08 15:26:07 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./get_next_line.h"

int		search_nwl(char **temp_buff, char **line)
{
	char *str_ch;

	if ((str_ch = ft_strchr(*temp_buff, '\n')))
	{
		*line = ft_strsub(*temp_buff, 0, (str_ch - *temp_buff));
		ft_strcpy(*temp_buff, str_ch + 1);
		return (1);
	}
	return (0);
}

char	*ft_cat(char *str1, char *str2)
{
	size_t	n1;
	size_t	n2;
	char	*cat;

	n1 = (str1) ? ft_strlen(str1) : 0;
	n2 = ft_strlen(str2);
	cat = ft_strnew(n1 + n2);
	if (cat)
	{
		if (str1)
			ft_memcpy(cat, str1, n1);
		ft_memcpy(cat + n1, str2, n2);
	}
	if (str1)
		ft_strdel(&str1);
	return (cat);
}

int		get_next_line(int const fd, char **line)
{
	int				nb_bytes;
	static	char	*temp_buff = NULL;
	char			buff[BUFF_SIZE + 1];

	if (temp_buff && search_nwl(&temp_buff, line))
		return (1);
	while ((nb_bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nb_bytes] = '\0';
		temp_buff = ft_cat(temp_buff, buff);
		if (search_nwl(&temp_buff, line))
			return (1);
	}
	if (nb_bytes < 0)
		return (-1);
	if (temp_buff && *temp_buff)
	{
		*line = ft_strdup(temp_buff);
		ft_strdel(&temp_buff);
		return (1);
	}
	if (nb_bytes)
		return (1);
	return (0);
}
