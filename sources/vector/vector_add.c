/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:49:21 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 17:19:24 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vector_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res = vector_new(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (res);
}
