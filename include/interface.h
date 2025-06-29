/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:50:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/29 11:25:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "fractal_context.h"
# include "config.h"
# include "initialize.h"
# include "libft.h"

void	parse_arg(int ac, char *av[], t_ctx *ctx);
void	get_option(char *av[], t_ctx *ctx);
void	show_help(void);
void	no_arg(char *program_name);
void	show_how_to_use(void);
int		ft_strcmp(char *s1, char *s2);

#endif