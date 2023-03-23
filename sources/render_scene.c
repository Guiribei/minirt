/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:07:55 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/23 20:08:26 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// lower_left_corner + u*horizontal + v*vertical - origin
static t_ray	ray_constructor(t_camera *camera, t_vector normal)
{
	t_ray		new;

	new.origin = camera->origin;
	new.direction = vector_diff(
			vector_sum(
				vector_sum(camera->lower_left_corner,
					vector_mult(camera->horizontal, normal.x)),
				vector_mult(camera->vertical, normal.y)),
			camera->origin);
	return (new);
}

static void	turn_on_camera(t_camera *camera)
{
	camera->viewport_height = -2.0;
	camera->viewport_width = (16.0 / 9.0) * camera->viewport_height;
	camera->focal_length = 1.0;
	camera->origin = vector_create(0, 0, 0);
	camera->horizontal = vector_create(camera->viewport_width, 0, 0);
	camera->vertical = vector_create(0, camera->viewport_height, 0);
	camera->lower_left_corner = vector_diff(
			vector_diff(
				vector_diff(camera->origin, vector_div(camera->horizontal, 2)),
				vector_div(camera->vertical, 2)),
			vector_create(0, 0, camera->focal_length));
}

void	render_scene(t_minirt *minirt)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_color		color;

	ft_bzero(&normal, 1);
	ft_bzero(&loop, 1);
	ft_bzero(&color, 1);
	ft_bzero(&ray, 1);
	turn_on_camera(&minirt->camera);
	while (loop.x < WIDTH)
	{
		loop.y = 0;
		while (loop.y < HEIGHT)
		{
			normal.x = (double)loop.x / (WIDTH - 1);
			normal.y = (double)loop.y / (HEIGHT - 1);
			ray = ray_constructor(&minirt->camera, normal);
			color = ray_color(ray);
			mlx_pixel_draw(&minirt->img, loop.x, loop.y,
				color_create_rgb(&color));
			loop.y++;
		}
		loop.x++;
	}
}