/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_and_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:45:55 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/30 17:30:14 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter_map_ok(t_long *d)
{
	if (d->count_c == 0)
	{
		free_tab(d);
		write(2, "Error\nNeed some collectibles in the map\n", 42);
		return (0);
	}
	if (d->count_p != 1)
	{
		free_tab(d);
		write(2, "Error\nChange the number of Player to 1\n", 39);
		return (0);
	}
	if (d->count_e == 0)
	{
		free_tab(d);
		write(2, "Error\nDoor(s) requiered\n", 24);
		return (0);
	}
	if (d->tab_x > 42 || d->tab_y > 79)
	{
		free_tab(d);
		write(2, "Error\nmap is too big\n", 21);
		return (0);
	}
	return (1);
}

int	check_other_char_in_map(t_long *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->tab[i])
	{
		j = 0;
		while (d->tab[i][j])
		{
			if (d->tab[i][j] != 'P' && d->tab[i][j] != '0' &&
				d->tab[i][j] != 'C' && d->tab[i][j] != 'E' &&
				d->tab[i][j] != '1')
			{
				write (2, "Error\nWrong Characters\n", 23);
				free_tab(d);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	counter_map(t_long *d)
{
	int	i;
	int	j;

	ft_init_struct_count(d);
	i = 0;
	while (d->tab[i])
	{
		j = 0;
		while (d->tab[i][j])
		{
			if (d->tab[i][j] == 'P')
				d->count_p++;
			else if (d->tab[i][j] == 'C')
				d->count_c++;
			else if (d->tab[i][j] == 'E')
				d->count_e++;
			j++;
		}
		i++;
	}
	if (check_other_char_in_map(d) == 0)
		return (0);
	if (counter_map_ok(d) == 0)
		return (0);
	return (1);
}

int	ft_first_read(t_long *d, char *str)
{
	d->fichier = open(str, 0);
	if (d->fichier == -1)
	{
		write (2, "Error\n", 6);
		close (d->fichier);
		return (0);
	}
	ft_memset_so_long(d->tab, 0, sizeof(d->tab));
	d->i = 0;
	d->j = 0;
	d->line = get_next_line(d->fichier);
	if (d->line == NULL)
	{
		close (d->fichier);
		free_tab(d);
		write (2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_read_map(t_long *d, char *str)
{
	if (ft_first_read(d, str) == 0)
		return (0);
	while (d->line != NULL)
	{
		d->tab[d->i] = d->line;
		d->j = 0;
		while (d->tab[d->i][d->j] != '\n' && d->tab[d->i][d->j] != '\0')
		{
			if (d->tab[d->i][d->j] == 'C')
				d->count++;
			d->j++;
		}
		d->tab[d->i][d->j] = '\0';
		d->i++;
		d->line = get_next_line(d->fichier);
	}
	d->tab[d->i] = NULL;
	d->tab_y = d->j;
	d->tab_x = d->i;
	close (d->fichier);
	return (1);
}
