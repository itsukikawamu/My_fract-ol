/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:59:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:17:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	no_arg(char *program_name)
{
	ft_printf("Usage:    %s type-of-set [option]\n\n", program_name);
	ft_printf("Set List: m(mandelbrot), j(julia), M(3d-mandelbrot),"\
		" n(newton-fractal)\n\n");
	ft_printf("Use \"--help\" or \"-h\" for more information.\n");
	exit(1);
}

void	invalid_option(void)
{
	ft_printf("invalid option\n");
	ft_printf("Use \"--help\" or \"-h\" for more information.\n");
	exit(1);
}

void	show_how_to_use(void)
{
	ft_printf("===== Controls =====\n");
	ft_printf("keys\t\tactions\n");
	ft_printf("-----------------------\n");
	ft_printf("ESC\t\tExit the program\n");
	ft_printf("Arrow keys\tMove view\n");
	ft_printf("i\t\tZoom in\n");
	ft_printf("o\t\tZoom out\n");
	ft_printf("u\t\tSUper zoom in\n");
	ft_printf("p\t\tSuper zoom out\n");
	ft_printf("c\t\tChange color theme\n");
	ft_printf("Mouse wheel\tZoom at mouse position\n");
	ft_printf("Left click\tCenter view at clicked position\n");
}

void	show_help(void)
{
	ft_printf("Usage: fractal type-of-set [options]\n\n");
	ft_printf("Set List: m(mandelbrot), j(julia), M(3d-mandelbrot),"\
		"n(newton-fractal)\n\n");
	ft_printf("Options:\n");
	ft_printf("\t-c\tselect other constant parameter patern for julia (A-E)\n");
	ft_printf("\t-z\tselect other initial value patern for mandelbrot (A-E)\n");
	exit(0);
}
