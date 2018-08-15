/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:53:33 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:11:04 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	rev_place_piece(t_map_piece *info, t_player *me)
{
	while (info->p_y >= info->p_top_start)
	{
		info->place_ret = (info->y_place -
				(info->p_bottom_end - info->p_top_start) < 0 ? 2 : 0);
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
			info->place_coordinate_y = info->m_y - info->p_top_start;
			info->m_x++;
			info->p_x++;
		}
		info->m_y--;
		info->p_y--;
	}
}

int		rev_move(t_map_piece *info)
{
	if (info->place_ret == 1)
	{
		info->y_place--;
		info->x_placeb = 0;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_placeb++;
	return (0);
}

void	rev_algo_2(t_map_piece *info, t_player *me)
{
	copy_tmp_map(info);
	get_shape_num_p(info);
	init_place_piece(info);
	rev_place_piece(info, me);
	get_os_xs_num(info);
	get_temp_os_xs(info);
}

void	rev_algo_4(t_map_piece *info, t_player *me)
{
	rev_algo_2(info, me);
	if (!(check_placement(info, me)))
	{
		send_coordinate(info);
		info->mod++;
		info->y_place = info->y_rows - 1;
		algo_3(info);
	}
	else
	{
		if (!rev_move(info))
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

void	map4_algo(t_map_piece *info, t_player *me)
{
	if (me->my_shape == 'X')
	{
		if (info->mod % 2)
			algo_4(info, me);
		else
			algo_4b(info, me);
	}
	else
	{
		if (info->mod % 2)
			rev_algo_4b(info, me);
		else
			rev_algo_4(info, me);
	}
}
