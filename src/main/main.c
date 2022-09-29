/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:59 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:48:59 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "game.h"
#include "handler.h"
#include "init.h"
#include "mlx.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		throw_error("Error: no file argument\n");
	init(&game);
	parse(argv[1], &game);
	start_game(&game);
	mlx_hook(game.gl.win_ptr, KeyPress, 0, &keypress_handler, &game);
	mlx_hook(game.gl.win_ptr, KeyExit, 0, &close_game, &game);
	mlx_loop(game.gl.mlx_ptr);
	return (0);
}