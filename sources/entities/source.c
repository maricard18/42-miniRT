/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:25:05 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 18:33:49 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_lightsource *source_new(char **point, char *brightness, char **color)
{
	t_lightsource	*lightsource;

	lightsource = nc_calloc(1, sizeof(t_lightsource));
	if (!lightsource)
		return (NULL);
	*lightsource = (t_lightsource)
	{
		.origin.x = ft_atof(point[0]),
		.origin.y = ft_atof(point[1]),
		.origin.z = ft_atof(point[2]),
		.brightness = ft_atof(brightness),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2])
	};
	return (lightsource);
}

t_lightsource *source_copy(t_lightsource *lightsource)
{
	t_lightsource	*copy;

	copy = nc_calloc(1, sizeof(t_lightsource));
	if (!copy)
		return (NULL);
	*copy = *lightsource;
	return (copy);
}

void	source_print(t_lightsource *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%f, %f, %f)\n", l->origin.x, l->origin.y, l->origin.z);
	printf("  Ratio: %f\n", l->brightness);
	printf("  Color: (%d, %d, %d)\n", l->color.r, l->color.g, l->color.b);
}
