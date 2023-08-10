/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:59:47 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_graphics(t_world *w)
{
	w->disp.mlx = mlx_init();
	if (!w->disp.mlx)
		message(w, ERROR_MALLOC("init_graphics (mlx)"));
	w->disp.win = mlx_new_window(w->disp.mlx, WIDTH, HEIGHT, "miniRT");
	if (!w->disp.win)
		message(w, ERROR_MALLOC("init_graphics (mlx window)"));
}

int	quit(t_world *world)
{
	destroy_world(&world);
	exit(EXIT_SUCCESS);
}

// t_light *l;
// l = nc_vector_at(w->lights, 0);

int	on_keypress(int keycode, t_world *w)
{
	if (keycode == ESC)
		quit(w);
	else if (keycode == W)
		w->camera.center.y += 5;
	else if (keycode == A)
		w->camera.center.x -= 5;
	else if (keycode == S)
		w->camera.center.y -= 5;
	else if (keycode == D)
		w->camera.center.x += 5;
	else if (keycode == C)
		w->camera.center.z -= 5;
	else if (keycode == V)
		w->camera.center.z += 5;
	render(w);
	return (keycode);
}

void	init_viewport(t_world *w)
{
	double	ratio;

	ratio = RATIO;
	w->wview = tan(RADIANS(w->camera.fov / 2.0));
	w->hview = w->wview / ratio;
	w->right = vec3_normalize(vec3_cross(w->camera.normal, UPGUIDE));
	w->up = vec3_normalize(vec3_cross(w->camera.normal, w->right));
	w->right = vec3_normalize(vec3_cross(w->camera.normal, w->up));
}

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		message(NULL, ERROR_USAGE);
	world = parse(argv[1]);
	init_viewport(world);
	init_graphics(world);
	world->disp.img = mlx_new_image(world->disp.mlx, WIDTH, HEIGHT);
	world->disp.addr = mlx_get_data_addr(world->disp.img, &world->disp.bpp, \
		&world->disp.line_length, &world->disp.endian);
	world_print(world);
	render(world);
	mlx_hook(world->disp.win, KeyPress, KeyPressMask, on_keypress, world);
	mlx_hook(world->disp.win, DestroyNotify, StructureNotifyMask, quit, world);
	mlx_loop(world->disp.mlx);
	destroy_world(&world);
	return (0);
}
