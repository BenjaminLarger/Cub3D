/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_check_corner.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:01:40 by blarger           #+#    #+#             */
/*   Updated: 2024/05/11 21:58:04 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* #include <math.h>
double val = 3.5;
double result = round(val);  // result is 4.0

#include <math.h>
double val = 3.7;
double result = floor(val);  // result is 3.0

#include <math.h>
double val = 3.2;
double result = ceil(val);  // result is 4.0
#include <math.h>
double val = -3.7;
double result = trunc(val);  // result is -3.0 */

static double	player_move_into_corner(t_data *data, t_corner *corner,
	double x, double y)
{
	if ((corner->north_est_blocked == true
			|| corner->north_west_blocked == true)
		&& ((int)y < (int)data->player_y))
		return (true);
	else if ((corner->south_est_blocked == true
			|| corner->south_west_blocked == true)
		&& ((int)y > (int)data->player_y))
		return (true);
	else if ((corner->north_est_blocked == true
			|| corner->north_est_blocked == true)
		&& ((int)x > (int)data->player_x))
		return (true);
	else if ((corner->north_west_blocked == true
			|| corner->north_west_blocked == true)
		&& ((int)x < (int)data->player_x))
		return (true);
	else
		return (false);
}

static double	check_deadlock_corner(t_data *data, t_corner *corner)
{
	int			x;
	int			y;

	x = (int)data->player_x;
	y = (int)data->player_y;
	if (can_move(data->map[y + 1][x]) == false
		&& can_move(data->map[y][x + 1] == false))
		corner->south_est_blocked = true;
	if (can_move(data->map[y + 1][x] == false)
		&& can_move(data->map[y][x - 1]) == false)
		corner->south_west_blocked = true;
	if (can_move(data->map[y - 1][x] == false)
		&& can_move(data->map[y][x + 1] == false))
		corner->north_est_blocked = true;
	if (can_move(data->map[y - 1] == false
			&& can_move(data->map[y][x - 1])) == false)
		corner->north_west_blocked = true;
	if (corner->north_est_blocked == true
		|| corner->north_west_blocked == true
		|| corner->south_est_blocked == true
		|| corner->south_west_blocked == true)
		return (true);
	else
		return (false);
}

bool	move_in_corner(t_data *data, double x, double y)
{
	t_corner	corner;

	corner.north_est_blocked = false;
	corner.north_west_blocked = false;
	corner.south_est_blocked = false;
	corner.south_west_blocked = false;
	printf("diffx = %f, diffy = %f\n", fabs(x - trunc(x)), fabs(y - trunc(y)));
	if (fabs(x - trunc(x)) > 0.1 || fabs(y - trunc(y)) > 0.1)
		return (false);
	printf("close to a corner");
	if (check_deadlock_corner(data, &corner) == false)
		return (false);
	if (player_move_into_corner(data, &corner, x, y) == true)
		return (true);
	else
		return (false);	
}
