/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:23:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 21:40:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	scroll_zoom(int input, int x, int y, t_ctx *ctx);
static void	click_move(int x, int y, t_ctx *ctx);

int	mouse_handler(int input, int x, int y, t_ctx *ctx)
{
	if (input == SCROLL_UP || input == SCROLL_DOWN)
		scroll_zoom(input, x, y, ctx);
	else if (input == LEFT_CLICK)
		click_move(x, y, ctx);
	ctx->render_flag = RENDER_REQUEST;
	return (0);
}

static void	click_move(int x, int y, t_ctx *ctx)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - WINSIZE_X / 2) * (ctx->width / WINSIZE_X) + ctx->offset_re;
	mouse_im = (y - WINSIZE_Y / 2) * (ctx->width / WINSIZE_X) + ctx->offset_im;
	ctx->offset_re = mouse_re;
	ctx->offset_im = mouse_im;
	return ;
}

static void	scroll_zoom(int input, int x, int y, t_ctx *ctx)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - WINSIZE_X / 2) * (ctx->width / WINSIZE_X) + ctx->offset_re;
	mouse_im = (y - WINSIZE_Y / 2) * (ctx->width / WINSIZE_X) + ctx->offset_im;
	if (input == SCROLL_UP)
		ctx->width *= 0.8;
	else if (input == SCROLL_DOWN)
		ctx->width *= 1.25;
	ctx->offset_re = mouse_re - (x - WINSIZE_X / 2) * ctx->width / WINSIZE_X;
	ctx->offset_im = mouse_im - (y - WINSIZE_Y / 2) * ctx->width / WINSIZE_X;
	return ;
}
