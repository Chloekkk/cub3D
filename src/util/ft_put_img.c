/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:16:56 by nkim              #+#    #+#             */
/*   Updated: 2022/09/23 15:26:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}
