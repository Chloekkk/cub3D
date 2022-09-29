#include "raycast.h"

t_ray	raycast(t_game *game, double camera_x)
{
	t_ray	ray;
	int		hit;

	hit = 0;
	set_ray(&game->state, &ray, camera_x);
	while (hit == 0)
	{
		if (ray.side_dist.x < ray.side_dist.y)
			update_ray(&ray, X);
		else if (ray.side_dist.x > ray.side_dist.y)
			update_ray(&ray, Y);
		else
		{
			update_ray(&ray, X);
			update_ray(&ray, Y);
		}
		if (game->map_info.map[ray.map_y][ray.map_x] == WALL)
			hit = 1;
	}
	set_perp_wall_dist(&ray, &game->state.pos);
	return (ray);
}
