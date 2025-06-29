/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:11:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/29 11:25:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int ac, char *av[])
{
	t_ctx	ctx;

	parse_arg(ac, av, &ctx);
	set_event_handler(&ctx);
	show_how_to_use();
	draw_image(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
