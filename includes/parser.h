/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 12:49:33 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"

t_world	*parse(char *filename);

void	parse_map(t_world *world, char **map, int counters[3]);

char	**read_map(t_world *world, char *filename);

bool	identifying(t_world *world, char **tokens, int count[3]);

bool	parse_syntax(char **tokens, char *code);

bool	is_filename_valid(char *filename);

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3]);

bool	parse_camera(t_camera *cam, char **tokens, int counters[3]);

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3]);

bool	parse_plane(t_vector *shapes, char **tokens);

bool	parse_sphere(t_vector *shapes, char **tokens);

bool	parse_cylinder(t_vector *shapes, char **tokens);

bool	parse_double(char **nb);

bool	parse_rgb(char *color);

#endif
