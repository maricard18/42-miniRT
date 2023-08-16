/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/16 18:24:03 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	sphere_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vec3_sub(point, inter->shape->data.sp.center);
	return (normal);
}

t_vec3	cylinder_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vec3_sub(point, inter->a);
	if (vec3_compare(inter->a, inter->shape->data.cy.cap1))
		normal = vec3_scale(inter->shape->data.cy.normal, -1);
	else if (vec3_compare(inter->a, inter->shape->data.cy.cap2))
		normal = inter->shape->data.cy.normal;
	return (normal);
}

t_vec3	cone_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	n;
	double 	res;

	(void)ray;
	res = vec3_dot(inter->cp, inter->cp) / vec3_dot(inter->normal, inter->cp);
	n = vec3_scale(inter->cp, res);
	n = vec3_sub(inter->cp, n);
	inter->normal = n;
	return (n);
}

t_vec3	shape_normal(t_hit *inter, t_ray *ray)
{
	if (inter->shape->type == PLANE)
		return (inter->shape->data.pl.normal);
	else if (inter->shape->type == SPHERE)
		return (sphere_normal(inter, ray));
	else if (inter->shape->type == CYLINDER)
		return (cylinder_normal(inter, ray));
	else
		return (cone_normal(inter, ray));
}
