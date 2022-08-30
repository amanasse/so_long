/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:06:58 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/30 16:41:03 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_ESC 65307
# define BUFFER 100000

typedef struct s_long
{
	char	*tab[BUFFER];
	char	*line;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p;
	void	*herbe;
	void	*eau;
	void	*nanas;
	void	*porte;
	void	*m;
	int		fichier;
	int		i;
	int		j;
	int		tab_x;
	int		tab_y;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		h;
	int		l;
	int		count;
	int		count2;
	int		count_p;
	int		count_c;
	int		count_e;
}				t_long;

//check argv[1] = .ber :
int		ft_strcmp(char *s1, char *s2);
int		check_argv(char *str);

// Initialisation_map :
void	ft_init_struct_count(t_long *d);
void	ft_init_struct(t_long *d);
void	ft_init_images(t_long *d);
void	ft_memset_so_long(void *s, int c, size_t n);
void	print_map(t_long *d);

// Check_error_map :
int		map_is_ok(t_long *d);
int		wrong_format(t_long *d);
int		wrong_down_right(t_long *d);
int		wrong_up_left(t_long *d);

// Check_error_map2 :
int		ft_read_map(t_long *d, char *str);
int		counter_map_ok(t_long *d);
int		counter_map(t_long *d);
int		check_other_char_in_map(t_long *d);

// Destruction_map :
void	free_tab(t_long *d);
int		ft_strlen_so_long(char *str);
int		destroy_mlx(t_long *d);

// Parsing :
void	my_pars(t_long *d);
void	pars_p(t_long *d);
void	pars_for_line(t_long *d);

// moves :
int		deal_key(int key_code, t_long *d);
void	key_w(t_long *d);
void	key_d(t_long *d);

#endif
