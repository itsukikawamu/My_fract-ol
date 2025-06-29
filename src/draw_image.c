/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:38:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 21:59:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	paint_pixel(int x, int y, t_ctx *ctx);
static void	put_pixel_to_img(t_ctx *ctx, int x, int y, int color);
static void	clear_rendering_info(t_ctx *ctx);

void	draw_image(t_ctx *ctx)
{
	mlx_clear_window(ctx->mlx, ctx->win);
	clear_rendering_info(ctx);
	paint_image(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, 0, 0);
}

static void	clear_rendering_info(t_ctx *ctx)
{
	ft_bzero(ctx->addr, WINSIZE_Y * ctx->line);
	ctx->pixel_cnt = 0;
	ctx->x = 0;
	ctx->y = 0;
	ctx->render_flag = RENDER_ACTIVE;
}

void	paint_image(t_ctx *ctx)
{
	while (ctx->x < WINSIZE_X)
	{
		while (ctx->y < WINSIZE_Y)
		{
			paint_pixel(ctx->x, ctx->y, ctx);
			ctx->y++;
			if (++ctx->pixel_cnt >= PIXELS_PER_FRAME)
				return ;
		}
		ctx->y = 0;
		ctx->x++;
	}
	ctx->x = 0;
	ctx->render_flag = RENDER_ACTIVE;
	return ;
}

static void	paint_pixel(int x, int y, t_ctx *ctx)
{
	t_complex	point;
	int			iter_cnt;

	point.re = (x - WINSIZE_X / 2) * ctx->width / WINSIZE_X + ctx->offset_re;
	point.im = (y - WINSIZE_Y / 2) * ctx->width / WINSIZE_X + ctx->offset_im;
	iter_cnt = ctx->is_set(point, ctx);
	if (iter_cnt == -1)
		put_pixel_to_img(ctx, x, y, WHITE);
	else
		put_pixel_to_img(ctx, x, y, get_color(iter_cnt, ctx));
	return ;
}

static void	put_pixel_to_img(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;

	dst = ctx->addr + (y * ctx->line + x * (ctx->bpp / 8));
	*(unsigned int *)dst = color;
}
