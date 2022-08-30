/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:54:26 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/30 15:48:01 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_p(t_long *d)
{
	d->p_x = d->x;
	d->p_y = d->y;
	d->tab[d->i][d->j] = '0';
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p, d->x * 32, d->y * 32);
}

void	pars_for_line(t_long *d)
{
	if (d->tab[d->i][d->j] == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->eau, d->x * 32, d->y * 32);
	else if (d->tab[d->i][d->j] == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->herbe, d->x * 32, d->y * 32);
	else if (d->tab[d->i][d->j] == 'P')
		pars_p(d);
	else if (d->tab[d->i][d->j] == 'C')
	{
		d->count++;
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->nanas, d->x * 32, d->y * 32);
	}
	else if (d->tab[d->i][d->j] == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->porte, d->x * 32, d->y * 32);
}

void	my_pars(t_long *d)
{
	while (d->tab[d->i])
	{
		d->x = 0;
		d->j = 0;
		while (d->tab[d->i][d->j] != '\0')
		{
			pars_for_line(d);
			d->j++;
			d->x++;
		}
		d->i++;
		d->y++;
	}
}
