/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:40:05 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/31 17:12:42 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	afficher_le_compteur(int key_code, t_long *d)
{
	if (key_code == KEY_ESC)
		destroy_mlx(d);
	d->str_itoa = ft_itoa(d->count2++);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->b, 0, 0);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 11, 20, 0xFF7F00, d->str_itoa);
	free(d->str_itoa);
	return (0);
}

void	free_tab(t_long *d)
{
	int	i;

	i = 0;
	while (d->tab[i])
	{
		free(d->tab[i]);
		i++;
	}
}

void	destroy_img(t_long *d)
{
	if (d->p)
		mlx_destroy_image(d->mlx_ptr, d->p);
	if (d->p_dos)
		mlx_destroy_image(d->mlx_ptr, d->p_dos);
	if (d->p_droite)
		mlx_destroy_image(d->mlx_ptr, d->p_droite);
	if (d->p_gauche)
		mlx_destroy_image(d->mlx_ptr, d->p_gauche);
	if (d->eau)
		mlx_destroy_image(d->mlx_ptr, d->eau);
	if (d->herbe)
		mlx_destroy_image(d->mlx_ptr, d->herbe);
	if (d->nanas)
		mlx_destroy_image(d->mlx_ptr, d->nanas);
	if (d->porte)
		mlx_destroy_image(d->mlx_ptr, d->porte);
	if (d->b)
		mlx_destroy_image(d->mlx_ptr, d->b);
}

int	destroy_mlx(t_long	*d)
{
	if (d->mlx_ptr && d->win_ptr)
		destroy_img(d);
	if (d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	if (d->mlx_ptr)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	free_tab(d);
	exit (0);
}
