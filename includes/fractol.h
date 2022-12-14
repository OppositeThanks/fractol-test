/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:14:45 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/19 15:34:08 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# define HEIGHT 600
# define WIDTH 800
# define MAX_ITERATION 30
# define MANDELBROT 1
# define JULIA 2

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			set;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		max_it;
	double		kr;
	double		ki;
	double		sx;
	double		rx;
	double		fx;
	int			x;
	int			y;
	double		zoom;

}				t_data;

typedef struct s_rgba
{
	int			r;
	int			g;
	int			b;
	int			t;

}				t_rgb;

void			help_mess(t_data *data);
void			clear_exit(int exit_code, t_data *data);
void			init(t_data *data);
void			get_julia_starting_values(t_data *data, int ac, char **av);
int				msg(char *str1, char *str2, int errnbr);
double			ft_atof(char *str);
void			my_scrollhook(double xdelta, double ydelta, void *param);
void			render(t_data *data);
#endif