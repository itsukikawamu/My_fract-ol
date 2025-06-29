/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:32:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:17:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static void	get_type(char *av1, t_ctx *ctx);
static void	invalid_type(char *type);

void	parse_arg(int ac, char *av[], t_ctx *ctx)
{
	if (ac == 0)
		no_arg(av[0]);
	get_type(av[1], ctx);
	get_option(av + 2, ctx);
	set_ctx(ctx);
	return ;
}

static void	get_type(char *av1, t_ctx *ctx)
{
	if (ft_strcmp(av1, "--help") == 0 || ft_strcmp(av1, "-h") == 0)
		show_help();
	if (ft_strcmp(av1, "m") == 0)
		ctx->type = MANDELBROT;
	else if (ft_strcmp(av1, "j") == 0)
		ctx->type = JULIA;
	else if (ft_strcmp(av1, "M") == 0)
		ctx->type = MANDELBROT3D;
	else if (ft_strcmp(av1, "n") == 0)
		ctx->type = NEWTON;
	else
		invalid_type(av1);
	return ;
}

static void	invalid_type(char *type)
{
	ft_printf("The type %s is not avilable.\n", type);
	ft_printf("Set List: m(mandelbrot), j(julia), M(3d-mandelbrot),"\
		" n(newton-fractal)\n\n");
	exit(1);
}
