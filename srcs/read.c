/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:15:32 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:10:48 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	init_player(t_player *player)
{
	char	*line;

	get_next_line(0, &line);
	if ((!(ft_strncmp(line, "$$$ exec p", 10))))
	{
		if (line[10] == '1')
		{
			player->id = '1';
			player->my_shape = 'O';
			player->current_shape = 'o';
		}
		else
		{
			player->id = '2';
			player->my_shape = 'X';
			player->current_shape = 'x';
		}
		ft_strdel(&line);
		return ;
	}
	return ;
}

void	m_size(t_map_piece *map)
{
	char	*line;
	char	*x_pos;
	char	*y_pos;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Plateau ", 8))
		get_next_line(0, &line);
	if (!(ft_strncmp(line, "Plateau ", 8)))
	{
		y_pos = ft_strchr(line, ' ');
		map->y_rows = ft_atoi(y_pos);
		map->y_place = map->y_rows - 1;
		map->y_placeb = 0;
		y_pos++;
		x_pos = ft_strchr(y_pos, ' ');
		map->x_cols = ft_atoi(x_pos);
		map->x_place = map->x_cols - 1;
		free(line);
		return ;
	}
}

void	read_map(t_map_piece *info)
{
	char	**map;
	char	*begin;
	int		i;
	int		x;

	i = 0;
	info->map = (char**)malloc(sizeof(*map) * info->y_rows);
	get_next_line(0, &begin);
	while (ft_strncmp(begin, "000 ", 4))
		get_next_line(0, &begin);
	while (i < (info->y_rows))
	{
		x = 0;
		info->map[i] = (char *)malloc(sizeof(char) * info->x_cols + 1);
		while (x < info->x_cols)
		{
			info->map[i][x] = begin[x + 4];
			x++;
		}
		info->map[i][x] = '\0';
		if (i < (info->y_rows - 1))
			get_next_line(0, &begin);
		i++;
	}
}

void	read_piece(t_map_piece *info)
{
	char	**piece;
	char	*begin;
	int		i;
	int		x;

	i = 0;
	if (!(info->piece = (char**)malloc(sizeof(*piece) * info->y_piece)))
		return ;
	get_next_line(0, &begin);
	while (ft_strncmp(begin, ".", 1) && ft_strncmp(begin, "*", 1))
		get_next_line(0, &begin);
	while (i < (info->y_piece))
	{
		x = 0;
		info->piece[i] = (char *)malloc(sizeof(char) * info->x_piece + 1);
		while (x < info->x_piece)
		{
			info->piece[i][x] = begin[x];
			x++;
		}
		info->piece[i][x] = '\0';
		if (i < (info->y_piece - 1))
			get_next_line(0, &begin);
		i++;
	}
}

void	piece_size(t_map_piece *piece)
{
	char	*line;
	char	*x_pos;
	char	*y_pos;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Piece ", 6))
		get_next_line(0, &line);
	if (!(ft_strncmp(line, "Piece ", 6)))
	{
		y_pos = ft_strchr(line, ' ');
		piece->y_piece = ft_atoi(y_pos);
		y_pos++;
		x_pos = ft_strchr(y_pos, ' ');
		piece->x_piece = ft_atoi(x_pos);
		free(line);
		return ;
	}
}
