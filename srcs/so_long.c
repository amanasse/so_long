/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:12:35 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/31 14:31:47 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_long	d;

	(void)argc;
	if (argc == 2)
	{
		if (check_argv (argv[1]) == 0)
			return (0);
		if (ft_read_map (&d, argv[1]) == 0)
			return (0);
		if (map_is_ok (&d) == 0)
			return (0);
		if (counter_map(&d) == 0)
			return (0);
		ft_init_struct(&d);
		my_pars(&d);
		mlx_key_hook(d.win_ptr, deal_key, &d);
		mlx_hook(d.win_ptr, 33, 1L << 17, destroy_mlx, &d);
		mlx_loop(d.mlx_ptr);
	}
	else
		write (2, "Error\nError of Arguments\n", 25);
	return (0);
}
