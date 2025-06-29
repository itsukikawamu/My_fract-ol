# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 22:48:21 by ikawamuk          #+#    #+#              #
#    Updated: 2025/06/29 11:44:55 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lbsd
AR = ar
ARFLAGS = rcs
RM = rm -f
RMDIR = rm -rf

SRCDIR = src
# BONUS_SRCDIR = src/bonus
OBJDIR = obj
# BONUS_OBJDIR = obj/bonus
INCDIR = include
LIBFTDIR = libft
MLXDIR = minilibx-linux
TMPDIR = ar_tmp

SRCFILES =	main.c\
			parse_arg.c\
			show_help.c\
			get_option.c\
			set_ctx.c\
			set_event_handler.c\
			mouse_handler.c\
			key_handler.c\
			draw_image.c\
			get_color.c\
			is_mandelbrot_set.c\
			is_julia_set.c\
			is_newton_fractal.c\
			is_mandelbrot_3d_set.c\
			is_set.c\
			utils.c\
			ft_complex.c\

# BONUS_SRCFILES = $(patsubst %.c, %_bonus.c, $(SRCFILES))

SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
BONUS_SRCS = $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

BONUS_OBJS = $(patsubst $(BONUS_SRCDIR)/%.c, $(BONUS_OBJDIR)/%.o, $(BONUS_SRCS))

INCLUDES = $(INCDIR) $(LIBFTDIR)/include $(MLXDIR)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx_Linux.a

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all

all: $(LIBFT) $(MLX) $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX): $(MLXDIR)
	$(MAKE) -C $(MLXDIR)

$(MLXDIR):
	git clone https://github.com/42Paris/minilibx-linux.git

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# $(BONUS_OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
# 	@mkdir -p $(BONUS_OBJDIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	@$(RMDIR) $(OBJDIR) $(BONUS_OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(MLX) $(NAME) $(BONUS_NAME)

re: fclean all

bonus: all

# $(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@	

# test: all
# 	@$(CC) $(CFLAGS) test.c $(LIBFT) -o test
# 	$(VALGRIND) $(VALGRIND_FLAGS) ./test

.PHONY:all clean fclean re test bonus
