/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:30:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:26:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "config.h"
# include "fractal_context.h"
# include "mlx.h"
# include "libft.h"

# define WHITE 0x00ffffff

void	draw_image(t_ctx *ctx);
void	paint_image(t_ctx *ctx);
int		get_color(int iter_cnt, t_ctx *ctx);

#endif