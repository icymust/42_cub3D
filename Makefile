NAME = cub3d
BONUS_NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

SRCS = src/main.c 

BONUS = 

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
LIBFT = lib/libft/libft.a
MLX_DIR = lib/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C lib/libft

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(MLX_LIB) $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(MLX) $(LIBFT) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C lib/libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C lib/libft fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus