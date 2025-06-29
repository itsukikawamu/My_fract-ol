/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 03:15:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:22:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static void	get_char_option(char *av[], int *i, t_ctx *ctx);
static void	invalid_option(void);

void	get_option(char *av[], t_ctx *ctx)
{
	int	i;

	ctx->option_char = 0;
	i = 0;
	while (av[i])
	{
		get_char_option(av, &i, ctx);
		i++;
	}
}

static void	get_char_option(char *av[], int *i, t_ctx *ctx)
{
	if (ft_strcmp(av[*i], "-c") == 0 && ctx->type == JULIA)
	{
		(*i)++;
		if (ft_strlen(av[*i]) != 1 || !ft_strchr("ABCDE", av[*i][0]))
			invalid_option();
		ctx->option_char = av[*i][0];
	}
	else if (ft_strcmp(av[*i], "-z") == 0 && ctx->type == MANDELBROT)
	{
		(*i)++;
		if (ft_strlen(av[*i]) != 1 || !ft_strchr("ABCDE", av[*i][0]))
			invalid_option();
		ctx->option_char = av[*i][0];
	}
	else
		invalid_option();
	return ;
}

static void	invalid_option(void)
{
	ft_printf("invalid option\n");
	ft_printf("Use \"--help\" or \"-h\" for more information.\n");
	exit(1);
}
