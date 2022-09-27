// cub3D structure
#ifndef CUB3D_H
# define CUB3D_H

# include "graphic.h"
# include "handler.h"
# include <stdio.h>

# define IMG_PATH "./img/"

# define WHITESPACE " \t\v\f\r\n"

# define DIR_TEXTURE_CNT 4
# define COLOR_CNT 2
# define IMG_SIZE 64

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define MINI_WIN_SIZE 200

# define STEP 0.1
# define THETA 0.03
// # define MINIMAP_PLAYER MINI_IMG_SIZE / 2

# define EMPTY '0'
# define WALL '1'
# define SPACE ' '

# define SUCCESS 0
# define FAIL -1

typedef struct s_ray
{
	t_point				ray_dir;
	t_point				side_dist;
	t_point				delta_dist;
	int					map_x;
	int					map_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					side;
	// double				ratio;
}						t_ray;

typedef struct s_map_info
{
	char				**map;
	int					width;
	int					height;
}						t_map_info;

typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA
}						t_dir;

typedef enum e_arrow
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}						t_arrow;

typedef enum e_color_type
{
	F,
	C
}						t_color_type;

typedef enum e_side
{
	X,
	Y
}						t_side;

typedef struct s_graphic_info
{
	void				*texture[4];
	int					color[2];
}						t_graphic_info;

typedef struct s_mini_graphic_info
{
	void				*wall;
	void				*space;
	int					width;
	int					height;
	int					b_size;
}						t_mini_graphic_info;

typedef struct s_gl
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_gl;

typedef struct s_state
{
	t_point				pos;
	t_point				mini_pos;
	t_point				dir;
	t_point				plane;
}						t_state;

typedef struct s_game
{
	t_gl				gl;
	t_map_info			map_info;
	t_graphic_info		graphic_info;
	t_mini_graphic_info	minimap_info;
	t_state				state;
}						t_game;

#endif