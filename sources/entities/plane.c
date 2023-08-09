/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 11:44:14 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	plane_new(char **c, char **n, char **cl)
{
	t_plane	plane;

	plane = (t_plane)
	{
		.point = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.normal = vec3_new(nc_atof(n[X]), nc_atof(n[Y]), nc_atof(n[Z])), 
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])),
	};
	return (plane);
}

bool	plane_intersect(t_plane *pl, t_ray *ray, t_inter *inter)
{
		(void) inter;
		t_vec3	co;
		double 	numerator;
		double 	denominator;
		double 	t;

		if (vec3_dot(ray->direction, vec3_add(pl->normal, vec3_new(EPSILON, EPSILON, EPSILON))) != 0.0)
		{
			co = vec3_sub(ray->origin, pl->point);
			numerator = vec3_dot(co, vec3_add(pl->normal, vec3_new(EPSILON, EPSILON, EPSILON)));
			denominator = vec3_dot(ray->direction, vec3_add(pl->normal, vec3_new(EPSILON, EPSILON, EPSILON)));
			t = -(numerator / denominator);
			if (t > EPSILON)
			{
				inter->t = t;
				inter->color = pl->color;
				return (true);			
			}
	}
	return (false);
}
