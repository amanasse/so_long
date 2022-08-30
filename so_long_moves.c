/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:43:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/30 16:58:07 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_s(t_long *d)
{
	if (d->tab[d->p_y + 1][d->p_x] == '0' || d->tab[d->p_y + 1][d->p_x] == 'C')
	{
		if (d->tab[d->p_y + 1][d->p_x] == 'C')
		{
			d->tab[d->p_y + 1][d->p_x] = '0';
			d->count--;
		}
		ft_printf("%d\n", d->count2++);
		d->p_y++;
	}
	else if (d->tab[d->p_y + 1][d->p_x] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_y++;
			ft_printf("%d\n", d->count2++);
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

void	key_a(t_long *d)
{
	if (d->tab[d->p_y][d->p_x - 1] == '0' || d->tab[d->p_y][d->p_x - 1] == 'C')
	{
		if (d->tab[d->p_y][d->p_x - 1] == 'C')
		{
			d->tab[d->p_y][d->p_x - 1] = '0';
			d->count--;
		}
		ft_printf("%d\n", d->count2++);
		d->p_x--;
	}
	else if (d->tab[d->p_y][d->p_x - 1] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_x--;
			ft_printf("%d\n", d->count2++);
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

void	key_w(t_long *d)
{
	if (d->tab[d->p_y - 1][d->p_x] == '0' || d->tab[d->p_y - 1][d->p_x] == 'C')
	{
		if (d->tab[d->p_y - 1][d->p_x] == 'C')
		{
			d->tab[d->p_y - 1][d->p_x] = '0';
			d->count--;
		}
		ft_printf("%d\n", d->count2++);
		d->p_y--;
	}
	else if (d->tab[d->p_y - 1][d->p_x] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_y--;
			ft_printf("%d\n", d->count2++);
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

void	key_d(t_long *d)
{
	if (d->tab[d->p_y][d->p_x + 1] == '0' || d->tab[d->p_y][d->p_x + 1] == 'C')
	{
		if (d->tab[d->p_y][d->p_x + 1] == 'C')
		{
			d->tab[d->p_y][d->p_x + 1] = '0';
			d->count--;
		}
		ft_printf("%d\n", d->count2++);
		d->p_x++;
	}
	else if (d->tab[d->p_y][d->p_x + 1] == 'E')
	{
		if (d->count == 0)
		{	
			d->p_x++;
			ft_printf("%d\n", d->count2++);
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
				d->p_x * 32, d->p_y * 32);
			destroy_mlx(d);
		}
	}
}

int	deal_key(int key_code, t_long *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->herbe,
		d->p_x * 32, d->p_y * 32);
	if (key_code == KEY_W)
		key_w(d);
	else if (key_code == KEY_D)
		key_d(d);
	else if (key_code == KEY_A)
		key_a(d);
	else if (key_code == KEY_S)
		key_s(d);
	else if (key_code == KEY_ESC)
		destroy_mlx(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p,
		d->p_x * 32, d->p_y * 32);
	return (0);
}
