/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:15:20 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/30 15:47:56 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] != '.' && i > 0)
		i--;
	if (str[i] == '.')
	{
		if (ft_strcmp (&str[i], ".ber\0") == 0)
			return (1);
		else
		{
			write (2, "Error\nthe map isnt a '.ber'\n", 28);
			return (0);
		}
	}
	write (2, "Error\nthe map isnt a '.ber'\n", 28);
	return (0);
}

int	wrong_up_left(t_long *d)
{
	d->j = 0;
	while (d->tab[0][d->j])
	{
		if (d->tab[0][d->j] != '1')
			return (0);
		d->j++;
	}
	d->i = 0;
	while (d->tab[d->i] != NULL)
	{
		if (d->tab[d->i][0] != '1')
			return (0);
		d->i++;
	}
	return (1);
}

int	wrong_down_right(t_long *d)
{
	d->j = 0;
	while (d->tab[d->i - 1][d->j])
	{
		if (d->tab[d->i - 1][d->j] != '1')
			return (0);
		d->j++;
	}
	d->i = 0;
	d->j = 0;
	while (d->tab[d->i])
	{
		d->j = 0;
		while (d->tab[d->i][d->j])
			d->j++;
		if (d->tab[d->i][d->j - 1] != '1')
			return (0);
		d->i++;
	}
	return (1);
}

int	wrong_format(t_long *d)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen_so_long (d->tab[0]);
	while (d->tab[i])
	{
		if (j != ft_strlen_so_long(d->tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	map_is_ok(t_long *d)
{
	if (wrong_format(d) == 0)
	{
		free_tab(d);
		write (2, "Error\nWrong Format\n", 19);
		return (0);
	}
	else if (wrong_up_left(d) == 0)
	{
		free_tab(d);
		write (2, "Error\nWrong Map\n", 17);
		return (0);
	}
	else if (wrong_down_right(d) == 0)
	{
		free_tab(d);
		write (2, "Error\nWrong Map2\n", 17);
		return (0);
	}
	return (1);
}
