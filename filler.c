/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:30:30 by tnghondz          #+#    #+#             */
/*   Updated: 2018/07/09 16:55:05 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

void	init_player(int fd, t_player *player)
{
	char	*line;
	
	get_next_line(fd, &line);
	if((!(ft_strncmp(line, "$$$ exec p", 10))))
	{
		if(line[10] == '1')
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
}

void	m_size(int fd, t_map_piece *map)
{
	char	*line;
	char	*x_pos;
	char	*y_pos;

	get_next_line(fd, &line);
	while(ft_strncmp(line, "Plateau ", 8))
		get_next_line(fd, &line);
	if(!(ft_strncmp(line, "Plateau ", 8)))
	{
		y_pos = ft_strchr(line, ' ');
		map->y_rows = ft_atoi(y_pos);
		y_pos++;
		x_pos = ft_strchr(y_pos, ' ');
		map->x_cols = ft_atoi(x_pos);
		free(line);
		return ;
	}
	
}
void read_map(int fd, t_map_piece *read_map_into)
{
	char	**map;
	char	*begin;
	int		i;

	i = 0;
	if(!(map = (char**) malloc (sizeof(*map) * read_map_into->y_rows)))
		return ;
	get_next_line(fd, &begin);
	while(ft_strncmp(begin, "000 ", 4))
		get_next_line(fd, &begin);
	while(i < (read_map_into->y_rows))
	{
		map[i] =  begin + 4;
		if(i < (read_map_into->y_rows - 1))
			get_next_line(fd, &begin);
		i++;
	}
	free(begin);
	read_map_into->map = map;
}

void copy_tmp_map(t_map_piece *read_tmp_into)
{
	char	**tmp;

	if(!(tmp = (char**) malloc (sizeof(*tmp) * read_tmp_into->y_rows)))
		return ;
	tmp = read_tmp_into->map;
	read_tmp_into->temp_map = tmp;
}

void	read_piece(int fd, t_map_piece *read_piece_into)
{
	char	**piece;
	char	*begin;
	int		i;

	i = 0;
	if(!(piece = (char**) malloc (sizeof(*piece) * read_piece_into->y_piece)))
		return ;
	get_next_line(fd, &begin);
	while(ft_strncmp(begin, ".", 1) && ft_strncmp(begin, "*", 1))
		get_next_line(fd, &begin);
	while(i < (read_piece_into->y_piece))
	{
		piece[i] =  begin;
		if(i < (read_piece_into->y_piece - 1))
			get_next_line(fd, &begin);
		i++;
	}
	free(begin);
	read_piece_into->piece = piece;
}

void	piece_size(int fd, t_map_piece *piece)
{
	char	*line;
	char	*x_pos;
	char	*y_pos;

	get_next_line(fd, &line);
	while(ft_strncmp(line, "Piece ", 6))
		get_next_line(fd, &line);
	if(!(ft_strncmp(line, "Piece ", 6)))
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
/*
void start_map(char **map, t_map_piece *m_info, t_player *me)
{
	int m_x;
	int m_y;

	m_y = 0;
	while(m_y < m_info->y_rows)
	{
		m_x = 0;
		while(map[m_y][m_x] != '\0')
		{
			if(map[m_y][m_x] == me->my_shape)
			{
				m_info->m_start_x = m_x;
				m_info->m_start_y = m_y;
				return ;
			}
			m_x++;
		}
		m_y++;
	}
}

void start_piece(char ** piece, t_map_piece *p_info)
{
	int p_x;
	int p_y;

	p_y = 0;
	while(p_y < p_info->y_piece)
	{
		p_x = 0;
		while(piece[p_y][p_x] != '\0')
		{
			if(piece[p_y][p_x] == '*')
			{
				p_info->p_first_x = p_x;
				p_info->p_first_y = p_y;
				return ;
			}
			p_x++;
		}
		p_y++;
	}
}
*/
void get_shape_num_p(t_map_piece *p_info)
{
	int x;
	int y;
	int shapes;

	y = 0;
	shapes = 0;
	while(y < p_info->y_piece)
	{
		x = 0;
		while(x < p_info->x_piece)
		{
			if(p_info->piece[y][x] == '*')
				shapes++;
			x++;
		}
		y++;
	}
	p_info->add_num = shapes;
}

void get_os_xs_num(t_map_piece *p_info)
{
    int x;
    int y;
    int os;
	int xs;

    y = 0;
    os = 0;
	xs = 0;
    while(y < p_info->y_rows)
    {
        x = 0;
        while(x < p_info->x_cols)
        {
            if(p_info->map[y][x] == 'O' || p_info->map[y][x] == 'o')
                os++;
			else if(p_info->map[y][x] == 'X' || p_info->map[y][x] == 'x')
				xs++;
            x++;
        }
        y++;
    }
    p_info->os_num = os;
	p_info->xs_num = xs;
}

void get_temp_os_xs(t_map_piece *p_info)
{
    int x;
    int y;
    int os;
	int xs;

    y = 0;
    os = 0;
	xs = 0;
    while(y < p_info->y_rows)
    {
        x = 0;
        while(x < p_info->x_cols)
        {
            if(p_info->temp_map[y][x] == 'O' || p_info->temp_map[y][x] == 'o')
                os++;
			else if(p_info->temp_map[y][x] == 'X' || p_info->temp_map[y][x] == 'x')
				xs++;
            x++;
        }
        y++;
    }
    p_info->temp_os = os;
	p_info->temp_xs = xs;
}

/*
void find_left_start_p(char **piece, t_map_piece *info)
{
	int	x;
	int	y;

	x = 0;
	while(x < info->x_piece)
	{
char **map;
	char ** piece;
		y = 0;
		while(y < info->y_piece)
		{
			if(piece[y][x] == '*')
			{
				info->p_left_start = x;
				return ;
			}
			y++;
		}
		x++;
	}
}
char **map;
	char ** piece;

void find_top_start_p(char **piece, t_map_piece *info)
{
	int	x;
	int	y;

	y = 0;
	while(y < info->y_piece)
	{
		x = 0;
		while(x < info->y_piece)void get_os_num(char **map, t_map_piece *p_info)
		{
			if(piece[y][x] == '*')
			{
				info->p_top_start = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void find_right_end_p(char **piece, t_map_piece *info)
{
	int	x;
	int	y;

	x = info->x_piece - 1;
	while(x > 0)
	{
		y = info->y_piece - 1;
		while(y > 0)
		{
			if(piece[y][x] == '*')
			{
				info->p_right_end = x;
				return ;
			}
			y--;
		}
		x--;
	}
}

void find_bottom_end_p(char **piece, t_map_piece *info)
{
	int	x;
	int	y;

	x = info->x_piece - 1;
	while(x > 0)
	{
		y = info->y_piece - 1;
		while(y > 0)
		{
			if(piece[y][x] == '*')
			{
				info->p_bottom_end = y;
				return ;
			}
			y--;
		}
		x--;
	}
}
*/

/*int place_piece(char **map, char **piece, t_map_piece *mp_info, t_player *me)
{
	int x_m;
	int y_m;
	int x_p;
	int y_p;
	int p_shapes;

	while(y_p < mp_info->y_piece)
	{
		x_p = 0;
		while(x_p < mp_info->x_piece)
		{
			if(piece[y_p][x_p] == '*' && map[m_start_y + y_p][m_start_x + x_p] == '.')
			{
				map[m_start_y + y_p][m_start_x + x_p] = me->my_shape;
				p_shapes--;
			}
			else
			{
				m_start_x++;
				start_map(map, mp_info, me);
			}
		}
	}
}
*/

int main(int argc, char **argv)
{
	t_player *me;
	t_map_piece *map_size;
	int m = 0;
	int p = 0;
		
	if (argc == 1) return (0);
  	int fd = open(argv[1], O_RDONLY);
 	me = (t_player *) malloc (sizeof(*me));
	init_player(fd,me);
	map_size  = (t_map_piece *) malloc (sizeof(*map_size));
	m_size(fd, map_size);
	read_map(fd, map_size);
	copy_tmp_map(map_size);
	piece_size(fd, map_size);
	read_piece(fd, map_size);
	get_shape_num_p(map_size);
	get_os_xs_num(map_size);
	get_temp_os_xs(map_size);
	printf("%d %d %d %d %d\n", map_size->add_num, map_size->os_num, map_size->xs_num, map_size->temp_os, map_size->temp_xs);
//	start_map(map, map_size, me);
//	start_piece(piece, map_size);
//	printf("map x: %i map y: %i\n",map_size->x_cols, map_size->y_rows);
	while(m < map_size->y_rows-1)
	{
		ft_putstr(map_size->map[m]);
		if(m != map_size->y_rows)
			ft_putchar('\n');
		m++;
	}
	while(p < map_size->y_piece)
	{
		ft_putstr(map_size->piece[p]);
	//	if(m != map_size->y_rows)
			ft_putchar('\n');
		p++;
	}
	

/*	find_left_start_p(piece, map_size);
	find_bottom_end_p(piece, map_size);
	find_top_start_p(piece, map_size);
	find_right_end_p(piece, map_size);
	printf("left start: %i, top start: %i, right end: %i, bottom end: %i", map_size->p_left_start, map_size->p_top_start, map_size->p_right_end, map_size->p_bottom_end);*/
//	ft_putnbr(get_shape_num_p(piece, map_size));
//	printf("%i %i\n", map_size->y_piece, map_size->x_piece);
 	close(fd);
}
