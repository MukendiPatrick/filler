/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pieceB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:14:47 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:10:35 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	place_pieceb(t_map_piece *info, t_player *me)
{
	while (info->p_y <= info->p_bottom_end)
	{
		info->place_ret = (info->y_placeb + (info->p_bottom_end -
					info->p_top_start + 1) > info->y_rows ? 2 : 0);
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
			info->place_coordinate_y = info->y_placeb - info->p_top_start;
			info->m_x--;
			info->p_x--;
		}
		info->m_y++;
		info->p_y++;
	}
}

void	init_place_pieceb(t_map_piece *info)
{
	info->place_ret = 0;
	info->p_y = info->p_top_start;
	info->m_y = info->y_placeb;
}

int		moveb(t_map_piece *info)
{
	if (info->place_ret == 1)
	{
		info->y_placeb++;
		info->x_place = info->x_cols - 1;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_place--;
	return (0);
}

void	algo_2b(t_map_piece *info, t_player *me)
{
	copy_tmp_map(info);
	get_shape_num_p(info);
	init_place_pieceb(info);
	place_pieceb(info, me);
	get_os_xs_num(info);
	get_temp_os_xs(info);
}

void	algo_4b(t_map_piece *info, t_player *me)
{
	algo_2b(info, me);
	if (!(check_placement(info, me)))
	{
		send_coordinate(info);
		info->mod++;
		info->y_placeb = 0;
		algo_3(info);
	}
	else
	{
		if (!moveb(info))
		{
			copy_tmp_map(info);
		}
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}
