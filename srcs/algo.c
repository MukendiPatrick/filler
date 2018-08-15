/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:31 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/13 14:10:13 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	init_struct(t_map_piece *info)
{
	info->x_place = 0;
	info->y_place = 0;
	info->y_placeb = 0;
	info->mod = 0;
	info->place_ret = 0;
	info->add_num = 0;
	info->os_num = 0;
	info->xs_num = 0;
	info->temp_os = 0;
	info->temp_xs = 0;
	info->place_coordinate_x = 0;
	info->place_coordinate_y = 0;
}

void	algo_1(t_map_piece *info, t_player *me)
{
	init_player(me);
	m_size(info);
	read_map(info);
	piece_size(info);
	read_piece(info);
	trim(info);
	copy_tmp_map(info);
}

void	algo_2(t_map_piece *info, t_player *me)
{
	copy_tmp_map(info);
	get_shape_num_p(info);
	init_place_piece(info);
	place_piece(info, me);
	get_os_xs_num(info);
	get_temp_os_xs(info);
}

void	algo_3(t_map_piece *info)
{
	free(info->map);
	read_map(info);
	info->x_piece = 0;
	info->y_piece = 0;
	piece_size(info);
	free(info->piece);
	read_piece(info);
	trim(info);
}

void	algo_4(t_map_piece *info, t_player *me)
{
	algo_2(info, me);
	if (!(check_placement(info, me)))
	{
		send_coordinate(info);
		info->mod++;
		info->y_place = info->y_rows - 1;
		algo_3(info);
	}
	else
	{
		if (!move(info))
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
