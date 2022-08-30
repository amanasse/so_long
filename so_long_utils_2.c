/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:40:05 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/30 15:48:03 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_mlx(t_long	*d)
{
	if (d->mlx_ptr && d->win_ptr)
	{
		if (d->p)
			mlx_destroy_image(d->mlx_ptr, d->p);
		if (d->eau)
			mlx_destroy_image(d->mlx_ptr, d->eau);
		if (d->herbe)
			mlx_destroy_image(d->mlx_ptr, d->herbe);
		if (d->nanas)
			mlx_destroy_image(d->mlx_ptr, d->nanas);
		if (d->porte)
			mlx_destroy_image(d->mlx_ptr, d->porte);
	}
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
