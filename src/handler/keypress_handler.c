/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:46 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 21:16:16 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "handler.h"
#include "math.h"
#include "parse.h"

static void	move_pos(int key, t_state *state, char **map)
{
	t_point	next_pos;

	if (key == KEY_W)
		set_pos(&next_pos, state->pos.x + STEP * state->dir.x,
			state->pos.y + STEP * state->dir.y);
	else if (key == KEY_D)
		set_pos(&next_pos, state->pos.x + STEP * state->plane.x,
			state->pos.y + STEP * state->plane.y);
	else if (key == KEY_A)
		set_pos(&next_pos, state->pos.x + -STEP * state->plane.x,
			state->pos.y + -STEP * state->plane.y);
	else if (key == KEY_S)
		set_pos(&next_pos, state->pos.x + -STEP * state->dir.x,
			state->pos.y + -STEP * state->dir.y);
	else
		return ;
	if (check_wall_collision(next_pos, state, map) == SUCCESS)
		set_pos(state, next_pos.x, next_pos.y);
}

static void	rotate_pos(int key, t_point *dir, t_point *plane)
{
	t_point	prev_dir;
	t_point	prev_plane;

	prev_dir = *dir;
	prev_plane = *plane;
	if (key == KEY_RD)
	{
		dir->x = (prev_dir.x * cos(THETA)) - (prev_dir.y * sin(THETA));
		dir->y = (prev_dir.x * sin(THETA)) + (prev_dir.y * cos(THETA));
		plane->x = (prev_plane.x * cos(THETA)) - (prev_plane.y * sin(THETA));
		plane->y = (prev_plane.x * sin(THETA)) + (prev_plane.y * cos(THETA));
	}
	else if (key == KEY_LD)
	{
		dir->x = (prev_dir.x * cos(-THETA)) - (prev_dir.y * sin(-THETA));
		dir->y = (prev_dir.x * sin(-THETA)) + (prev_dir.y * cos(-THETA));
		plane->x = (prev_plane.x * cos(-THETA)) - (prev_plane.y * sin(-THETA));
		plane->y = (prev_plane.x * sin(-THETA)) + (prev_plane.y * cos(-THETA));
	}
}

int	keypress_handler(int key, t_game *game)
{
	if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
	{
		mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
		move_pos(key, &game->state, game->map_info.map);
		draw_game(game);
		draw_minimap(game);
	}
	else if (key == KEY_LD || key == KEY_RD)
	{
		mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
		rotate_pos(key, &game->state.dir, &game->state.plane);
		draw_game(game);
		draw_minimap(game);
	}
	if (key == KEY_ESC)
		close_game(game);
	return (SUCCESS);
}
