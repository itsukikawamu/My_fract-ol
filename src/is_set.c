/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 06:02:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 22:00:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_set.h"

static bool		diverges(t_complex z);
static double	complex_distance_sq(t_complex a, t_complex b);

int	is_divergent_set(t_complex z, t_complex c, t_div_rel rel, t_ctx *ctx)
{
	int	i;

	i = 0;
	while (!diverges(z) && i < ctx->max_iter)
	{
		z = rel(z, c);
		i++;
	}
	if (i == ctx->max_iter)
		return (-1);
	return (i);
}

static bool	diverges(t_complex z)
{
	if (z.re * z.re + z.im * z.im > 4)
		return (true);
	return (false);
}

bool	converges(t_complex z, t_complex limit)
{
	if (complex_distance_sq(z, limit) < EPSILON2)
		return (true);
	return (false);
}

static double	complex_distance_sq(t_complex a, t_complex b)
{
	return ((a.re - b.re) * (a.re - b.re) + (a.im - b.im) * (a.im - b.im));
}
