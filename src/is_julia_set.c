/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_julia_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:10:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 12:32:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_set.h"

static t_complex	julia_relation(t_complex z, t_complex c);
static void			julia_max_iter(t_ctx *ctx);
static t_complex	get_initial_value(t_ctx *ctx);

int	is_julia_set(t_complex z, t_ctx *ctx)
{
	t_complex	c;

	c = get_initial_value(ctx);
	julia_max_iter(ctx);
	return (is_divergent_set(z, c, julia_relation, ctx));
}

static t_complex	get_initial_value(t_ctx *ctx)
{
	if (ctx->option_char == 'B')
		return ((t_complex){-1, 0});
	if (ctx->option_char == 'C')
		return ((t_complex){0.295, -0.02});
	if (ctx->option_char == 'D')
		return ((t_complex){-0.804, -0.1652});
	if (ctx->option_char == 'E')
		return ((t_complex){0, 0});
	return ((t_complex){-0.75, 0.1});
}

static t_complex	julia_relation(t_complex z, t_complex c)
{
	t_complex	new_z;

	new_z.re = z.re * z.re - z.im * z.im + c.re;
	new_z.im = 2 * z.re * z.im + c.im;
	return (new_z);
}

static void	julia_max_iter(t_ctx *ctx)
{
	double	scale;

	scale = 4.0 / ctx->width;
	ctx->max_iter = (int)(30 + log2(scale) * 50);
	if (ctx->max_iter < 150)
		ctx->max_iter = 150;
	return ;
}
