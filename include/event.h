/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:13:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:06:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "fractal_context.h"
# include "render.h"

# define LEFT_CLICK		1
# define RIGHT_CLICK	3
# define MIDDLE_CLICK	2
# define SCROLL_UP		4
# define SCROLL_DOWN	5

void	set_event_handler(t_ctx *ctx);
int		mouse_handler(int input, int x, int y, t_ctx *ctx);
int		key_handler(int key, t_ctx *ctx);
int		exit_fractal(t_ctx *ctx);

#endif