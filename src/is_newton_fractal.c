/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_newton_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:33:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:02:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_set.h"

static void			newton_max_iter(t_ctx *ctx);
static t_complex	newton_step(t_complex z);
static int			find_root_idx(t_complex z, const t_complex root[3]);

int	is_newton_fractal(t_complex z, t_ctx *ctx)
{
	int				i;
	const t_complex	root[3] = {
		(t_complex){1, 0},
		(t_complex){-0.5, sqrt(3) / 2},
		(t_complex){-0.5, -sqrt(3) / 2}
	};

	newton_max_iter(ctx);
	i = 0;
	while (i < ctx->max_iter)
	{
		ctx->root_idx = find_root_idx(z, root);
		if (ctx->root_idx != -1)
			break ;
		z = newton_step(z);
		i++;
	}
	if (ctx->root_idx == -1)
		return (-1);
	ctx->base_color = 0x0fff0000;
	ctx->base_color >>= ctx->root_idx * 8;
	return (i);
}

static int	find_root_idx(t_complex z, const t_complex root[3])
{
	int	idx;

	idx = 0;
	while (idx < 3)
	{
		if (converges(z, root[idx]))
			return (idx);
		idx++;
	}
	return (-1);
}

static t_complex	newton_step(t_complex z)
{
	t_complex	z2;
	t_complex	z3;
	t_complex	num;
	t_complex	div;

	z2 = ft_complex_mul(z, z);
	z3 = ft_complex_mul(z2, z);
	num = (t_complex){z3.re * 2.0, z3.im * 2.0};
	num.re += 1;
	div = (t_complex){z2.re * 3.0, z2.im * 3.0};
	return (ft_complex_div(num, div));
}

static void	newton_max_iter(t_ctx *ctx)
{
	double	scale;
	double	factor;

	if (ctx->width <= 4.0)
	{
		scale = 4.0 / ctx->width;
		factor = log2(scale);
		ctx->max_iter = (int)(30 + factor * 10);
	}
	else
	{
		scale = ctx->width / 4.0;
		factor = log2(scale);
		ctx->max_iter = (int)(30 + factor * 10);
	}
}
