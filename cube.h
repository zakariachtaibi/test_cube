# ifndef CUBE_H
# define CUBE_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define MOVE_SPEED 0.1
#define ROT_SPEED 0.1
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    int map[MAP_WIDTH][MAP_HEIGHT];
    int key_states[256];
} t_data;

# endif