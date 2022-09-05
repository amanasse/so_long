/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:43:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/31 17:05:20 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_s(t_long *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->herbe,
		d->p_x * 32, d->p_y * 32);
	if (d->tab[d->p_y + 1][d->p_x] == '0' || d->tab[d->p_y + 1][d->p_x] == 'C')
	{
		if (d->tab[d->p_y + 1][d->p_x] == 'C')
		{
			d->tab[d->p_y + 1][d->p_x] = '0';
			d->count--;
		}
		d->p_y++;
	}
	else if (d->tab[d->p_y + 1][d->p_x] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_y++;
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

void	key_a(t_long *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->herbe,
		d->p_x * 32, d->p_y * 32);
	if (d->tab[d->p_y][d->p_x - 1] == '0' || d->tab[d->p_y][d->p_x - 1] == 'C')
	{
		if (d->tab[d->p_y][d->p_x - 1] == 'C')
		{
			d->tab[d->p_y][d->p_x - 1] = '0';
			d->count--;
		}
		d->p_x--;
	}
	else if (d->tab[d->p_y][d->p_x - 1] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_x--;
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_gauche,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

void	key_w(t_long *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->herbe,
		d->p_x * 32, d->p_y * 32);
	if (d->tab[d->p_y - 1][d->p_x] == '0' || d->tab[d->p_y - 1][d->p_x] == 'C')
	{
		if (d->tab[d->p_y - 1][d->p_x] == 'C')
		{
			d->tab[d->p_y - 1][d->p_x] = '0';
			d->count--;
		}
		d->p_y--;
	}
	else if (d->tab[d->p_y - 1][d->p_x] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_y--;
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_dos,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

void	key_d(t_long *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->herbe,
		d->p_x * 32, d->p_y * 32);
	if (d->tab[d->p_y][d->p_x + 1] == '0' || d->tab[d->p_y][d->p_x + 1] == 'C')
	{
		if (d->tab[d->p_y][d->p_x + 1] == 'C')
		{
			d->tab[d->p_y][d->p_x + 1] = '0';
			d->count--;
		}
		d->p_x++;
	}
	else if (d->tab[d->p_y][d->p_x + 1] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_x++;
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_droite,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

int	deal_key(int key_code, t_long *d)
{
	if (key_code == KEY_W)
	{
		key_w(d);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_dos,
			d->p_x * 32, d->p_y * 32);
	}
	else if (key_code == KEY_D)
	{
		key_d(d);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_droite,
			d->p_x * 32, d->p_y * 32);
	}
	else if (key_code == KEY_A)
	{
		key_a(d);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_gauche,
			d->p_x * 32, d->p_y * 32);
	}
	else if (key_code == KEY_S)
	{
		key_s(d);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
			d->p_x * 32, d->p_y * 32);
	}
	return (afficher_le_compteur(key_code, d));
}
