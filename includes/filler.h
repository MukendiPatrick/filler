/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:24:15 by tnghondz          #+#    #+#             */
/*   Updated: 2018/07/09 16:55:00 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "../libft/libft.h"

typedef struct	s_player
{
	char		id;
	char		my_shape;
	char		current_shape;
}				t_player;

typedef struct	s_map_piece
{
	int x_cols;
	int y_rows;
	
	int	x_piece;
	int	y_piece;
	
	int m_start_x;
	int m_start_y;
	
	int p_first_x;
	int p_first_y;

	int p_left_start;
	int p_top_start;
	int p_bottom_end;
	int p_right_end;

	int	add_num;
	int os_num;
	int xs_num;
	int temp_os;
	int temp_xs;

	char **map;
	char **piece;
	char **temp_map;

	int	place_coordinate_x;
	int	place_coordinate_y;
	

}				t_map_piece;
#endif
