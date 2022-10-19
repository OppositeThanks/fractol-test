/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thegroove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:31:14 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/19 16:52:53 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_cursorhook(double xpos, double ypos, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->zoom += 0.0;
	if (xpos || ypos)
		;
	render(data);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (xdelta)
		;
	if (ydelta > 0)
		data->zoom -= 0.25;
	else if (ydelta < 0)
		data->zoom += 0.25;
	mlx_cursor_hook(data->mlx, &my_cursorhook, (void *)data);
}

/* double zoom(t_data *data, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = data->min_r - data->max_r;
	center_i = data->min_i - data->max_i;
	data->max_r = data->max_r + (center_r - zoom * center_r) / 2;
	data->min_r = data->max_r + zoom * center_r;
	data->min_i = data->min_i + (center_i - zoom * center_i) / 2;
	data->max_i = data->min_i + zoom * center_i;
}

void	move(t_data *data, double dist, char dir)
{
	double	center_r;
	double	center_i;

	center_r = data->max_r - data->min_r;
	center_i = data->max_i - data->min_i;
	if (dir == 'R')
	{
		data->min_r += center_r * dist;
		data->max_r += center_r * dist;
	}
	else if (dir == 'L')
	{
		data->min_r -= center_r * dist;
		data->max_r -= center_r * dist;
	}
	else if (dir == 'D')
	{
		data->min_i -= center_i * dist;
		data->max_i -= center_i * dist;
	}
	else if (dir == 'U')
	{
		data->min_i += center_i * dist;
		data->max_i += center_i * dist;
	}
}

void	key_hook(int keycode, mlx_t *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, 'R');
	else
		return (1);
	render(&data, mlx);
}
 */