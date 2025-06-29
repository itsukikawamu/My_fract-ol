/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mandelbrot_3d_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:12:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:05:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_set.h"

static t_complex	mandelbrot_3d_relation(t_complex z, t_complex c);
static void			mandelbrot_max_iter(t_ctx *ctx);
static t_complex	get_initial_value(t_ctx *ctx);

int	is_mandelbrot_3d_set(t_complex c, t_ctx *ctx)
{
	t_complex	z;

	z = get_initial_value(ctx);
	mandelbrot_max_iter(ctx);
	return (is_divergent_set(z, c, mandelbrot_3d_relation, ctx));
}

static t_complex	get_initial_value(t_ctx *ctx)
{
	if (ctx->option_char == 'B')
		return ((t_complex){-1, 0});
	if (ctx->option_char == 'C')
		return ((t_complex){1.5, 0.5});
	if (ctx->option_char == 'D')
		return ((t_complex){0, -1});
	if (ctx->option_char == 'E')
		return ((t_complex){0.75, 0.75});
	return ((t_complex){0, 0});
}

static t_complex	mandelbrot_3d_relation(t_complex z, t_complex c)
{
	t_complex	new_z;

	new_z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
	new_z.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im + c.im;
	return (new_z);
}

static void	mandelbrot_max_iter(t_ctx *ctx)
{
	double	scale;

	scale = 4.0 / ctx->width;
	ctx->max_iter = (int)(30 + log2(scale) * 10);
	if (ctx->max_iter < 100)
		ctx->max_iter = 100;
	return ;
}
