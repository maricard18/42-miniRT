/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/17 20:17:41 by maricard         ###   ########.fr       */
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
	w->disp.img = mlx_new_image(w->disp.mlx, WIDTH, HEIGHT);
	if (!w->disp.img)
		message(w, ERROR_MALLOC("init_graphics (mlx image)"));
	w->disp.addr = mlx_get_data_addr(w->disp.img, &w->disp.bpp, \
		&w->disp.line_length, &w->disp.endian);
	if (!w->disp.addr)
		message(w, ERROR_MALLOC("init_graphics (mlx image address)"));
}

int	quit(t_world *world)
{
	destroy_world(&world);
	exit(EXIT_SUCCESS);
}

int	on_keypress(int keycode, t_world *w)
{
	t_light	*light;

	light = nc_vector_at(w->lights, 0);
	if (keycode == ESC)
		quit(w);
	else if (keycode == W)
		light->center.y += 5;
	else if (keycode == A)
		light->center.x -= 5;
	else if (keycode == S)
		light->center.y -= 5;
	else if (keycode == D)
		light->center.x += 5;
	else if (keycode == C)
		light->center.z -= 5;
	else if (keycode == V)
		light->center.z += 5;
	vec3_print(light->center);
	render(w);
	return (keycode);
}

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		message(NULL, ERROR_USAGE);
	world = parse(argv[1]);
	init_viewport(world);
	init_graphics(world);
	world_print(world);
	render(world);
	mlx_hook(world->disp.win, KeyPress, KeyPressMask, on_keypress, world);
	mlx_hook(world->disp.win, DestroyNotify, StructureNotifyMask, quit, world);
	mlx_loop(world->disp.mlx);
	destroy_world(&world);
	return (0);
}
