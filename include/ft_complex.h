/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:52:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/27 23:09:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

t_complex	ft_complex_add(t_complex a, t_complex b);
t_complex	ft_complex_sub(t_complex a, t_complex b);
t_complex	ft_complex_mul(t_complex a, t_complex b);
t_complex	ft_complex_div(t_complex a, t_complex b);
t_complex	ft_complex_pow(t_complex z, int n);

#endif