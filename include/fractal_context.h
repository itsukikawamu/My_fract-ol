/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_context.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:36:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:06:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_CONTEXT_H
# define FRACTAL_CONTEXT_H

# include <stdbool.h>
# include <stdlib.h>
# include "ft_complex.h"

# define RENDER_DONE     0
# define RENDER_REQUEST  1
# define RENDER_ACTIVE   2

typedef struct s_ctx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		line;
	int		en;
	char	*addr;
	int		type;
	char	option_char;
	double	width;
	double	offset_re;
	double	offset_im;
	int		max_iter;
	int		pixel_cnt;
	int		x;
	int		y;
	int		render_flag;
	int		(*is_set)(t_complex, struct s_ctx*);
	int		base_color;
	size_t	color_rotation;
	int		root_idx;
}	t_ctx;

#endif