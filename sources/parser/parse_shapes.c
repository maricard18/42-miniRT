/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/22 18:34:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;

	if (nc_matrix_size(tokens) != 6)
		return (ERROR_NUM_ARGS("plane", "6"), false);
	if (!parse_syntax(tokens, "011100"))
		return (ERROR_NUM_COMMAS("plane"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR_MISFORMAT_COLOR("plane"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (ERROR_KS_OUT_OF_BOUNDS("plane"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (ERROR_SHININESS_OUT_OF_BOUNDS("plane"), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (ERROR_VALUES_TOO_SMALL("plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_sphere	sphere;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (ERROR_NUM_ARGS("sphere", "6"), false);
	if (!parse_syntax(tokens, "010100"))
		return (ERROR_NUM_COMMAS("sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR_MISFORMAT_COLOR("sphere"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (ERROR_KS_OUT_OF_BOUNDS("sphere"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (ERROR_SHININESS_OUT_OF_BOUNDS("sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (ERROR_VALUES_TOO_SMALL("plane"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 8)
		return (ERROR_NUM_ARGS("cylinder", "8"), false);
	if (!parse_syntax(tokens, "01100100"))
		return (ERROR_NUM_COMMAS("cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (ERROR_MISFORMAT_COLOR("cylinder"), false);
	if (nc_atod(tokens[6]) < 0.0 || nc_atod(tokens[6]) > 1.0)
		return (ERROR_KS_OUT_OF_BOUNDS("cylinder"), false);
	if (nc_atod(tokens[7]) < 0.0)
		return (ERROR_SHININESS_OUT_OF_BOUNDS("cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (ERROR_VALUES_TOO_SMALL("plane"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size, tokens + 6);
	nc_vector_push(shapes, shape);
	return (true);
}

<<<<<<< HEAD
bool	parse_texture(t_vector *shapes, char **tokens)
{
	t_shape	*last;
	
	if (nc_matrix_size(tokens) < 2)
		return (ERROR_NUM_ARGS("checkerboard", "2"), false);
	if (!parse_plane(shapes, tokens))
		return (false);
	last = nc_vector_last(shapes);
	last->is_textured = true;
	return (true);
}
bool	parse_torus(t_vector *shapes, char **tokens)
=======
bool	parse_cone(t_vector *shapes, char **tokens)
>>>>>>> acad2b5... code: cone ongoing
{
	bool		ok;
	t_cone		cone;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (ERROR("Wrong number of args in cone (need 6)"), false);
	if (!parse_syntax(tokens, "011001"))
		return (ERROR("Misconfiguration in commas/numbers in cone"), false);
	if (!parse_rgb(tokens[5]))
		return (ERROR("Colors misformatting in cone"), false);
	ok = cone_from_strings(&cone, tokens);
	if (!ok)
		return (ERROR("Values are too small in cone"), false);
	shape = shape_new(&cone, CONE, shapes->size);
	nc_vector_push(shapes, shape);
	return (true);
}
