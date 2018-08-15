/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:32:19 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/10 16:14:20 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_player
{
	char		id;
	char		my_shape;
	char		current_shape;
}				t_player;

typedef	struct	s_map_piece
{
	int			x_cols;
	int			y_rows;
	int			x_piece;
	int			y_piece;
	int			x_place;
	int			y_place;
	int			y_placeb;
	int			x_placeb;
	int			place_ret;
	int			mod;
	int			p_left_start;
	int			p_top_start;
	int			p_bottom_end;
	int			p_right_end;
	int			add_num;
	int			os_num;
	int			xs_num;
	int			temp_os;
	int			temp_xs;
	char		**map;
	char		**piece;
	char		**temp_map;
	int			place_coordinate_x;
	int			place_coordinate_y;
	int			p_y;
	int			p_x;
	int			m_x;
	int			m_y;
}				t_map_piece;

void			init_player(t_player *player);
void			m_size(t_map_piece *map);
void			read_map(t_map_piece *read_map_into);
void			copy_tmp_map(t_map_piece *read_tmp_into);
void			read_piece(t_map_piece *read_piece_into);
void			piece_size(t_map_piece *piece);
void			init_place_piece(t_map_piece *info);
void			init_place_pieceb(t_map_piece *info);
void			place_piece(t_map_piece *info, t_player *me);
void			get_shape_num_p(t_map_piece *p_info);
void			get_os_xs_num(t_map_piece *p_info);
void			get_temp_os_xs(t_map_piece *p_info);
int				check_placement(t_map_piece *p_info, t_player *shape);
int				move(t_map_piece *info);
void			send_coordinate(t_map_piece *info);
void			init_struct(t_map_piece *info);
void			find_left_start_p(t_map_piece *info);
void			find_top_start_p(t_map_piece *info);
void			find_right_end_p(t_map_piece *info);
void			find_bottom_end_p(t_map_piece *info);
void			trim(t_map_piece *info);
void			algo_1(t_map_piece *info, t_player *me);
void			algo_2(t_map_piece *info, t_player *me);
void			algo_3(t_map_piece *info);
void			algo_4(t_map_piece *info, t_player *me);
void			algo_2b(t_map_piece *info, t_player *me);
void			algo_4b(t_map_piece *info, t_player *me);
void			rev_place_piece(t_map_piece *info, t_player *me);
int				rev_move(t_map_piece *info);
void			rev_algo_2(t_map_piece *info, t_player *me);
void			rev_algo_4(t_map_piece *info, t_player *me);
void			rev_place_pieceb(t_map_piece *info, t_player *me);
int				rev_moveb(t_map_piece *info);
void			rev_algo_2b(t_map_piece *info, t_player *me);
void			rev_algo_4b(t_map_piece *info, t_player *me);
void			map4_algo(t_map_piece *info, t_player *me);
void			gen_algo(t_map_piece *info, t_player *me);
#endif
