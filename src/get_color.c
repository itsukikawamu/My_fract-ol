/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 05:34:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/29 13:21:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	rotate_rgb(int color, int n);
static int	reverse_color(int color, int n);

int	get_color(int iter_cnt, t_ctx *ctx)
{
	int	color;

	color = (double)iter_cnt / ctx->max_iter * ctx->base_color;
	if (ctx->color_rotation % 11 == 1)
		return (color = rotate_rgb(color, 1));
	if (ctx->color_rotation % 11 == 2)
		return (color = rotate_rgb(color, 2));
	if (ctx->color_rotation % 11 == 3)
		return (color = ~color);
	if (ctx->color_rotation % 11 == 4)
		return (color = ~(rotate_rgb(color, 1)));
	if (ctx->color_rotation % 11 == 5)
		return (color = ~(rotate_rgb(color, 2)));
	if (ctx->color_rotation % 11 == 6)
		return (color = ((color << 4) & 0xff0000));
	if (ctx->color_rotation % 11 == 7)
		return (color = (color & 0x00ff00));
	if (ctx->color_rotation % 11 == 8)
		return (color = (color & 0x0000ff));
	if (ctx->color_rotation % 11 == 9)
		return (color = reverse_color(color, 6));
	if (ctx->color_rotation % 11 == 10)
		return (color = reverse_color(color, 12));
	return (color);
}

static int	reverse_color(int color, int n)
{
	int	rev;
	int	i;

	rev = 0;
	i = 0;
	while (i < 24 / n)
	{
		rev <<= n;
		rev |= (color & ((1 << n) - 1));
		color >>= n;
		i++;
	}
	return (rev);
}

static int	rotate_rgb(int color, int n)
{
	int	r;
	int	g;
	int	b;

	if (n % 3 == 0)
	{
		r = color & 0xFF0000;
		g = color & 0x00FF00;
		b = color & 0x0000FF;
	}
	else if (n % 3 == 1)
	{
		r = (color << 8) & 0xFF0000;
		g = (color << 8) & 0x00FF00;
		b = (color >> 16) & 0x0000FF;
	}
	else
	{
		r = (color << 16) & 0xFF0000;
		g = (color >> 8) & 0x00FF00;
		b = (color >> 8) & 0x0000FF;
	}
	return (r | g | b);
}
