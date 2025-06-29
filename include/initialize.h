/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:50:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 11:58:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "fractal_context.h"
# include "config.h"
# include "render.h"
# include "is_set.h"

void	set_ctx(t_ctx *ctx);
void	init_render_config(t_ctx *ctx);

#endif