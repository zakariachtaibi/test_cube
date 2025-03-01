#include "cube.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int map[MAP_WIDTH][MAP_HEIGHT] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Function to draw a pixel on the screen
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// Function to clear the screen with a background color
void clear_image(t_data *data, int color)
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            my_mlx_pixel_put(data, x, y, color);
        }
    }
}

// Function to handle window close event
int handle_close(void *param)
{
    t_data *data = (t_data *)param;
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

// Function to handle keypress events
int handle_keypress(int keycode, void *param)
{
    t_data *data = (t_data *)param;

    double newPosX = data->posX;
    double newPosY = data->posY;

    if (keycode == 53)  // ESC key
        handle_close(param);
    else if (keycode == 13)  // W key
    {
        newPosX += data->dirX * MOVE_SPEED;
        newPosY += data->dirY * MOVE_SPEED;
    }
    else if (keycode == 1)  // S key
    {
        newPosX -= data->dirX * MOVE_SPEED;
        newPosY -= data->dirY * MOVE_SPEED;
    }
    else if (keycode == 0)  // A key
    {
        newPosX -= data->dirY * MOVE_SPEED;
        newPosY += data->dirX * MOVE_SPEED;
    }
    else if (keycode == 2)  // D key
    {
        newPosX += data->dirY * MOVE_SPEED;
        newPosY -= data->dirX * MOVE_SPEED;
    }
    else if (keycode == 123)  // Left arrow key
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(-ROT_SPEED) - data->dirY * sin(-ROT_SPEED);
        data->dirY = oldDirX * sin(-ROT_SPEED) + data->dirY * cos(-ROT_SPEED);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(-ROT_SPEED) - data->planeY * sin(-ROT_SPEED);
        data->planeY = oldPlaneX * sin(-ROT_SPEED) + data->planeY * cos(-ROT_SPEED);
    }
    else if (keycode == 124)  // Right arrow key
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(ROT_SPEED) - data->dirY * sin(ROT_SPEED);
        data->dirY = oldDirX * sin(ROT_SPEED) + data->dirY * cos(ROT_SPEED);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(ROT_SPEED) - data->planeY * sin(ROT_SPEED);
        data->planeY = oldPlaneX * sin(ROT_SPEED) + data->planeY * cos(ROT_SPEED);
    }

    // Check if the new position is inside a wall
    if (map[(int)newPosX][(int)newPosY] == 0)
    {
        data->posX = newPosX;
        data->posY = newPosY;
    }

    return (0);
}

// Function to perform raycasting and draw the scene
void raycasting(t_data *data)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        // Calculate ray position and direction
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;  // X in camera space
        double rayDirX = data->dirX + data->planeX * cameraX;
        double rayDirY = data->dirY + data->planeY * cameraX;

        // Which box of the map we're in
        int mapX = (int)data->posX;
        int mapY = (int)data->posY;

        // Length of ray from one side to next in map
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        // Direction to step in (either +1 or -1)
        int stepX, stepY;

        // Length of ray from current position to next x or y-side
        double sideDistX, sideDistY;

        // Calculate step and initial sideDist
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
        }

        // Perform DDA (Digital Differential Analysis)
        int hit = 0;  // Was there a wall hit?
        int side;     // Was a NS or EW wall hit?
        while (hit == 0)
        {
            // Jump to next map square
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            // Check if ray has hit a wall
            if (map[mapX][mapY] == 1)
                hit = 1;
        }

        // Calculate distance projected on camera direction
        double perpWallDist;
        if (side == 0)
            perpWallDist = (mapX - data->posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - data->posY + (1 - stepY) / 2) / rayDirY;

        // Calculate height of line to draw on screen
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        // Draw the wall slice
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        // Choose a color based on the side
        int color;
        if (side == 0)
            color = 0xFF0000;  // Red for NS walls
        else
            color = 0x00FF00;  // Green for EW walls

        // Draw the vertical stripe
        for (int y = drawStart; y < drawEnd; y++)
        {
            my_mlx_pixel_put(data, x, y, color);
        }
    }
}

// Function to render each frame
int render_frame(void *param)
{
    t_data *data = (t_data *)param;

    // Clear the screen with a background color
    clear_image(data, 0x000000);  // Black background

    // Perform raycasting
    raycasting(data);

    // Update the window with the new image
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

    return (0);
}

int main(void)
{
    t_data data;

    // Initialize MLX
    data.mlx = mlx_init();
    if (!data.mlx)
    {
        fprintf(stderr, "Error: Failed to initialize MLX.\n");
        return (1);
    }

    // Create a window
    data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3D");
    if (!data.win)
    {
        fprintf(stderr, "Error: Failed to create window.\n");
        return (1);
    }

    // Create an image
    data.img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!data.img)
    {
        fprintf(stderr, "Error: Failed to create image.\n");
        return (1);
    }
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    // Initialize player position and direction
    data.posX = 2.0;
    data.posY = 2.0;
    data.dirX = -1.0;
    data.dirY = 0.0;
    data.planeX = 0.0;
    data.planeY = 0.66;

    // Set up hooks
    mlx_hook(data.win, 17, 0, handle_close, &data);  // Handle window close
    mlx_hook(data.win, 2, 1L<<0, handle_keypress, &data);  // Handle keypress
    mlx_loop_hook(data.mlx, render_frame, &data);  // Render loop

    // Start the MLX loop
    mlx_loop(data.mlx);

    return (0);
}