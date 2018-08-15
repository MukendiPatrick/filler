/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_place_pieceB.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:24:02 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:11:16 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	rev_place_pieceb(t_map_piece *info, t_player *me)
{
	while (info->p_y <= info->p_bottom_end)
	{
		info->place_ret = (info->y_placeb + (info->p_bottom_end -
					info->p_top_start + 1) > info->y_rows ? 2 : 0);
		if (info->place_ret == 2)
			return ;
		info->m_x = info->x_placeb;
		info->p_x = info->p_left_start;
		while (info->p_x <= info->p_right_end)
		{
			info->place_ret = (info->x_placeb + (info->p_right_end -
						info->p_left_start + 1) > info->x_cols ? 1 : 0);
			if (info->place_ret == 1)
				return ;
			if (info->piece[info->p_y][info->p_x] != '.')
				info->temp_map[info->m_y][info->m_x] = me->my_shape;
			info->place_coordinate_x = info->x_placeb - info->p_left_start;
			info->place_coordinate_y = info->y_placeb - info->p_top_start;
			info->m_x++;
			info->p_x++;
		}
		info->m_y++;
		info->p_y++;
	}
}

int		rev_moveb(t_map_piece *info)
{
	if (info->place_ret == 1)
	{
		info->y_placeb++;
		info->x_placeb = 0;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_placeb++;
	return (0);
}

void	rev_algo_2b(t_map_piece *info, t_player *me)
{
	copy_tmp_map(info);
	get_shape_num_p(info);
	init_place_pieceb(info);
	rev_place_pieceb(info, me);
	get_os_xs_num(info);
	get_temp_os_xs(info);
}

void	rev_algo_4b(t_map_piece *info, t_player *me)
{
	rev_algo_2b(info, me);
	if (!(check_placement(info, me)))
	{
		send_coordinate(info);
		info->mod++;
		info->y_placeb = 0;
		algo_3(info);
	}
	else
	{
		if (!rev_moveb(info))
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

void	gen_algo(t_map_piece *info, t_player *me)
{
	while (1)
	{
		if (info->y_rows == 15 || info->y_rows == 24)
		{
			if (me->my_shape == 'O')
			{
				if (info->mod % 2)
					algo_4(info, me);
				else
					algo_4b(info, me);
			}
			else
			{
				if (info->mod % 2)
					rev_algo_4(info, me);
				else
					rev_algo_4b(info, me);
			}
		}
		else
			map4_algo(info, me);
	}
}
