/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:12 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:42:21 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sphere_info1(t_world *w)
{
	display(w, (t_xy){10, 90}, 0xFFFF00, "W");
	display(w, (t_xy){10, 110}, 0xFFFF00, "S");
	display(w, (t_xy){10, 130}, 0xFFFF00, "A");
	display(w, (t_xy){10, 150}, 0xFFFF00, "D");
	display(w, (t_xy){10, 180}, 0xFFFF00, "UP");
	display(w, (t_xy){10, 200}, 0xFFFF00, "DOWN");
	display(w, (t_xy){10, 220}, 0xFFFF00, "LEFT");
	display(w, (t_xy){10, 240}, 0xFFFF00, "RIGHT");
	display(w, (t_xy){10, 270}, 0xFFFF00, "1");
	display(w, (t_xy){10, 290}, 0xFFFF00, "2");
	display(w, (t_xy){10, 310}, 0xFFFF00, "3");
	display(w, (t_xy){10, 330}, 0xFFFF00, "4");
	display(w, (t_xy){10, 350}, 0xFFFF00, "5");
	display(w, (t_xy){10, 370}, 0xFFFF00, "6");
	display(w, (t_xy){10, 390}, 0xFFFF00, "7");
	display(w, (t_xy){10, 420}, 0xFF0000, "Q");
}

void	sphere_info2(t_world *w)
{
	display(w, (t_xy){20, 90}, 0xFFFFFF, " - Move Foward");
	display(w, (t_xy){20, 110}, 0xFFFFFF, " - Move Backwards");
	display(w, (t_xy){20, 130}, 0xFFFFFF, " - Move Left");
	display(w, (t_xy){20, 150}, 0xFFFFFF, " - Move Right");
	display(w, (t_xy){25, 180}, 0xFFFFFF, " - Go Up");
	display(w, (t_xy){45, 200}, 0xFFFFFF, " - Go Down");
	display(w, (t_xy){45, 220}, 0xFFFFFF, " - Increase radius");
	display(w, (t_xy){50, 240}, 0xFFFFFF, " - Decrease radius");
	display(w, (t_xy){20, 270}, 0xFFFFFF, " - Color white");
	display(w, (t_xy){20, 290}, 0xFFFFFF, " - Color Yellow");
	display(w, (t_xy){20, 310}, 0xFFFFFF, " - Color Red");
	display(w, (t_xy){20, 330}, 0xFFFFFF, " - Color Green");
	display(w, (t_xy){20, 350}, 0xFFFFFF, " - Color Blue");
	display(w, (t_xy){20, 370}, 0xFFFFFF, " - Color Pink");
	display(w, (t_xy){20, 390}, 0xFFFFFF, " - Color Cyan");
	display(w, (t_xy){20, 420}, 0xFFFFFF, " - Previous menu");		
}
