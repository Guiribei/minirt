/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/20 19:30:08 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	1. Validate input.
*	2. Load .rt file in a t_raytracer struct (?)
*	3. Generate a scene using the struct...?
*	...
*/

// TODO:
int	main(void)
{
	t_minirt	minirt;

	mlx_open_window(&minirt.mlx);

	mlx_loop_window(&minirt.mlx);
	return (0);
}
