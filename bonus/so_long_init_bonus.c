/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:53:59 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/31 17:12:18 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_images(t_long *d)
{
	d->b = mlx_xpm_file_to_image(d->mlx_ptr, "./img/b.xpm", &d->l, &d->h);
	d->p = mlx_xpm_file_to_image(d->mlx_ptr, "./img/ADIBOU_Vert.xpm",
			&d->l, &d->h);
	d->p_dos = mlx_xpm_file_to_image(d->mlx_ptr, "./img/Adibou_dos.xpm",
			&d->l, &d->h);
	d->p_droite = mlx_xpm_file_to_image(d->mlx_ptr, "./img/Adibou_droite.xpm",
			&d->l, &d->h);
	d->p_gauche = mlx_xpm_file_to_image(d->mlx_ptr, "./img/Adibou_gauche.xpm",
			&d->l, &d->h);
	d->eau = mlx_xpm_file_to_image(d->mlx_ptr, "./img/eau.xpm",
			&d->l, &d->h);
	d->herbe = mlx_xpm_file_to_image(d->mlx_ptr, "./img/herbe2.xpm",
			&d->l, &d->h);
	d->nanas = mlx_xpm_file_to_image(d->mlx_ptr, "./img/ananas.xpm",
			&d->l, &d->h);
	d->porte = mlx_xpm_file_to_image(d->mlx_ptr, "./img/porte.xpm",
			&d->l, &d->h);
	if (!d->herbe || !d->porte || !d->nanas || !d->eau || !d->p
		|| !d->b || !d->p_dos || !d->p_droite || !d->p_gauche)
	{
		write(2, "Error\nProb with img\n", 22);
		destroy_mlx(d);
	}
}

void	ft_init_struct_count(t_long *d)
{
	d->count_c = 0;
	d->count_p = 0;
	d->count_e = 0;
}

void	check_mlx(t_long *d)
{
	if (d->mlx_ptr)
	{
		d->win_ptr = mlx_new_window(d->mlx_ptr,
				d->tab_y * 32, d->tab_x * 32, "ADIBOU");
		if (d->win_ptr)
			ft_init_images(d);
		else
			destroy_mlx(d);
	}
	else
		destroy_mlx(d);
}

void	ft_init_struct(t_long *d)
{
	d->i = 0;
	d->j = 0;
	d->y = 0;
	d->count = 0;
	d->count2 = 1;
	d->mlx_ptr = NULL;
	d->win_ptr = NULL;
	d->b = NULL;
	d->p = NULL;
	d->eau = NULL;
	d->herbe = NULL;
	d->nanas = NULL;
	d->porte = NULL;
	d->mlx_ptr = mlx_init();
	check_mlx(d);
}
