#ifndef PARSE_H
# define PARSE_H

# include "cub3D.h"

void	parse(char *filename, t_game *game);
void	valid_extension(char *fileName);
void	parse_map_info(t_map_info *map_info, int fd);
void	parse_graphic_info(t_graphic_info *graphic_info, int fd, void *mlx_ptr);
void	parse_state(t_state *state, t_map_info *map_info);

void	valid_map(t_game *game);
void	valid_edge_wall(t_map_info *map_info, int row);
void	valid_inner_wall(t_map_info *map, int row);

#endif