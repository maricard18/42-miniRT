/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/15 18:06:38 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	determinant(float a, float b, float c)
{
	float	delta;

	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (0);
	else if (delta < EPSILON)
		return (1);
	else
		return (2);
}

int	quadformula(float a, float b, float c, float *roots)
{
	float	x1;
	float	x2;
	float	delta;

	delta = determinant(a, b, c);
	if (delta == 0)
		return (0);
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (x1 < x2)
	{
		roots[0] = x1;
		roots[1] = x2;
	}
	else
	{
		roots[0] = x2;
		roots[1] = x1;
	}
	return (delta);
}

void	closest_point(float t, t_ray *ray, t_color *color)
{
	t_vec3	point;
	t_vec3	vec;
	float 	distance;

	point = vec3_add(ray->origin, vec3_scale(ray->direction, t));
	vec = vec3_sub(point, ray->origin);
	distance = vec3_module(vec);
	// Print the distance vs the ray closest distance
	if (distance < ray->distance + EPSILON)
	{
		// HERE;
		// printf("distance = %f\n", distance);
		// printf("ray->distance = %f\n", ray->distance);
		// printf("Painting: ");
		// color_print(color);
		ray->distance = distance;	
		ray->color = *color;
	}
}
