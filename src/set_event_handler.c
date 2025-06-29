/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:13:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 21:41:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static int	loop_handler(t_ctx *ctx);

void	set_event_handler(t_ctx *ctx)
{
	mlx_loop_hook(ctx->mlx, loop_handler, ctx);
	mlx_mouse_hook(ctx->win, mouse_handler, ctx);
	mlx_key_hook(ctx->win, key_handler, ctx);
	mlx_hook(ctx->win, DestroyNotify, 0, exit_fractal, ctx);
	return ;
}

int	exit_fractal(t_ctx *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->img);
	mlx_destroy_window(ctx->mlx, ctx->win);
	exit(0);
	return (0);
}

static int	loop_handler(t_ctx *ctx)
{
	if (ctx->render_flag == RENDER_REQUEST)
		draw_image(ctx);
	else
		paint_image(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, 0, 0);
	ctx->pixel_cnt = 0;
	return (0);
}
