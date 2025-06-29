/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:52:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 12:21:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	ft_complex_add(t_complex a, t_complex b)
{
	return ((t_complex){a.re + b.re, a.im + b.im});
}

t_complex	ft_complex_sub(t_complex a, t_complex b)
{
	return ((t_complex){a.re - b.re, a.im - b.im});
}

t_complex	ft_complex_mul(t_complex a, t_complex b)
{
	t_complex	mul;

	mul.re = a.re * b.re - a.im * b.im;
	mul.im = a.re * b.im + a.im * b.re;
	return (mul);
}

t_complex	ft_complex_div(t_complex a, t_complex b)
{
	t_complex	result;
	double		deno;

	deno = b.re * b.re + b.im * b.im;
	result.re = (a.re * b.re + a.im * b.im) / deno;
	result.im = (a.im * b.re - a.re * b.im) / deno;
	return (result);
}

t_complex	ft_complex_pow(t_complex z, int n)
{
	t_complex	res;
	int			i;

	res = (t_complex){1.0, 0.0};
	i = 0;
	while (i < n)
	{
		res = ft_complex_mul(res, z);
		i++;
	}
	return (res);
}
