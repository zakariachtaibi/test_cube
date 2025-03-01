CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = cube

SRCS = main.c

OBJS = $(SRCS:.c=.o)

MLX_PATH = mlx_linux
MLX_LIB = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_PATH)

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re