/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 06:03:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:03:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_SET_H
# define IS_SET_H

# include "fractal_context.h"
# include "config.h"
# include "render.h"
# include <math.h>

typedef t_complex	(*t_div_rel)(t_complex, t_complex);
typedef t_complex	(*t_con_rel)(t_complex);

int		is_mandelbrot_set(t_complex c, t_ctx *ctx);
int		is_mandelbrot_3d_set(t_complex c, t_ctx *ctx);
int		is_julia_set(t_complex z, t_ctx *ctx);
int		is_newton_fractal(t_complex z, t_ctx *ctx);
int		is_divergent_set(t_complex z, t_complex c, t_div_rel rel, t_ctx *ctx);
bool	converges(t_complex z, t_complex limit);

#endif