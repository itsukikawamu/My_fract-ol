/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:48:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 21:56:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "initialize.h"

static void	key_move(int key, t_ctx *ctx);
static void	key_zoom(int key, t_ctx *ctx);

int	key_handler(int key, t_ctx *ctx)
{
	if (key == XK_r)
		init_render_config(ctx);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		key_move(key, ctx);
	if (key == XK_i || key == XK_o || key == XK_u || key == XK_p)
		key_zoom(key, ctx);
	if (key == XK_Escape || key == XK_q)
		exit_fractal(ctx);
	if (key == XK_c)
		ctx->color_rotation++;
	ctx->render_flag = RENDER_REQUEST;
	return (0);
}

static void	key_move(int key, t_ctx *ctx)
{
	if (key == XK_Up)
		ctx->offset_im -= ctx->width / 10;
	else if (key == XK_Down)
		ctx->offset_im += ctx->width / 10;
	else if (key == XK_Left)
		ctx->offset_re -= ctx->width / 10;
	else if (key == XK_Right)
		ctx->offset_re += ctx->width / 10;
}

static void	key_zoom(int key, t_ctx *ctx)
{
	if (key == XK_i)
		ctx->width *= 0.8;
	else if (key == XK_o)
		ctx->width *= 1.25;
	else if (key == XK_u)
		ctx->width *= 0.1;
	else if (key == XK_p)
		ctx->width *= 10;
	return ;
}
