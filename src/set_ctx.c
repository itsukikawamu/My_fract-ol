/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:27:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:04:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"
#include <stdlib.h>
#include <stdio.h>

static void	init_img(t_ctx *ctx);
static void	init_is_set(t_ctx *ctx);
static void	init_color(t_ctx *ctx);

void	set_ctx(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
	ctx->win = mlx_new_window(ctx->mlx, WINSIZE_X, WINSIZE_Y, "fract-ol");
	init_img(ctx);
	init_render_config(ctx);
	init_is_set(ctx);
	init_color(ctx);
	return ;
}

void	init_render_config(t_ctx *ctx)
{
	ctx->width = 4.0;
	ctx->offset_re = 0;
	ctx->offset_im = 0;
	ctx->pixel_cnt = 0;
	ctx->x = 0;
	ctx->y = 0;
	ctx->render_flag = RENDER_REQUEST;
	return ;
}

static void	init_is_set(t_ctx *ctx)
{
	if (ctx->type == MANDELBROT)
		ctx->is_set = is_mandelbrot_set;
	else if (ctx->type == JULIA)
		ctx->is_set = is_julia_set;
	else if (ctx->type == MANDELBROT3D)
		ctx->is_set = is_mandelbrot_3d_set;
	else if (ctx->type == NEWTON)
		ctx->is_set = is_newton_fractal;
}

static void	init_color(t_ctx *ctx)
{
	ctx->base_color = mlx_get_color_value(ctx->mlx, WHITE);
	ctx->color_rotation = 0;
}

static void	init_img(t_ctx *ctx)
{
	ctx->img = mlx_new_image(ctx->mlx, WINSIZE_X, WINSIZE_Y);
	if (!ctx->img)
	{
		perror("mlx_new_image failed");
		exit(EXIT_FAILURE);
	}
	ctx->addr = mlx_get_data_addr(ctx->img, &ctx->bpp, &ctx->line, &ctx->en);
	if (!ctx->addr)
	{
		perror("mlx_get_data_addr failed");
		exit(EXIT_FAILURE);
	}
	return ;
}
