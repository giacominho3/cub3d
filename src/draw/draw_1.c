/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:26:07 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/01 11:12:37 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(t_game *g, int x, int y, int i)
{
	if (i == NORD)
		return (*(int *)(g->t.n.addr + (y * g->t.n.line_length
				+ x * g->t.n.bits_per_pixel / 8)));
	else if (i == SOUTH)
		return (*(int *)(g->t.s.addr + (y * g->t.s.line_length
				+ x * g->t.s.bits_per_pixel / 8)));
	else if (i == EAST)
		return (*(int *)(g->t.e.addr + (y * g->t.e.line_length
				+ x * g->t.e.bits_per_pixel / 8)));
	else if (i == WEST)
		return (*(int *)(g->t.w.addr + (y * g->t.w.line_length
				+ x * g->t.w.bits_per_pixel / 8)));
	return (0);
}
