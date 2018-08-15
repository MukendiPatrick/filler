/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:14:15 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:10:27 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	place_piece(t_map_piece *info, t_player *me)
{
	while (info->p_y >= info->p_top_start)
	{
		info->place_ret = (info->y_place -
				(info->p_bottom_end - info->p_top_start) < 0 ? 2 : 0);
		if (info->place_ret == 2)
			return ;
		info->m_x = info->x_place;
		info->p_x = info->p_right_end;
		while (info->p_x >= info->p_left_start)
		{
			if (info->x_place - (info->p_right_end - info->p_left_start) < 0)
			{
				info->place_ret = 1;
				return ;
			}
			if (info->piece[info->p_y][info->p_x] != '.')
				info->temp_map[info->m_y][info->m_x] = me->my_shape;
			info->place_coordinate_x = info->m_x - info->p_left_start;
			info->place_coordinate_y = info->m_y - info->p_top_start;
			info->m_x--;
			info->p_x--;
		}
		info->m_y--;
		info->p_y--;
	}
}

void	init_place_piece(t_map_piece *info)
{
	info->place_ret = 0;
	info->p_y = info->p_bottom_end;
	info->m_y = info->y_place;
}

void	get_shape_num_p(t_map_piece *p_info)
{
	int x;
	int y;
	int shapes;

	y = 0;
	shapes = 0;
	while (y < p_info->y_piece)
	{
		x = 0;
		while (x < p_info->x_piece)
		{
			if (p_info->piece[y][x] == '*')
				shapes++;
			x++;
		}
		y++;
	}
	p_info->add_num = shapes;
}

void	get_os_xs_num(t_map_piece *p_info)
{
	int x;
	int y;
	int os;
	int xs;

	y = 0;
	os = 0;
	xs = 0;
	while (y < p_info->y_rows)
	{
		x = 0;
		while (x < p_info->x_cols)
		{
			if (p_info->map[y][x] == 'O' || p_info->map[y][x] == 'o')
				os++;
			else if (p_info->map[y][x] == 'X' || p_info->map[y][x] == 'x')
				xs++;
			x++;
		}
		y++;
	}
	p_info->os_num = os;
	p_info->xs_num = xs;
}

void	get_temp_os_xs(t_map_piece *p_info)
{
	int x;
	int y;
	int os;
	int xs;

	y = 0;
	os = 0;
	xs = 0;
	while (y < p_info->y_rows)
	{
		x = 0;
		while (x < p_info->x_cols)
		{
			if (p_info->temp_map[y][x] == 'O' || p_info->temp_map[y][x] == 'o')
				os++;
			else if (p_info->temp_map[y][x] == 'X' ||
					p_info->temp_map[y][x] == 'x')
				xs++;
			x++;
		}
		y++;
	}
	p_info->temp_os = os;
	p_info->temp_xs = xs;
}
