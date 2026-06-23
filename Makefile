NAME = cub3D
BONUS_NAME = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

SRCS = src/main.c \
	src/game_utils.c \
	src/game_hooks.c \
	src/map.c \
	src/map_utils.c \
	src/map_check.c \
	src/map_read.c \
	src/map_closed.c \
	src/config.c \
	src/config_utils.c \
	src/config_color.c \
	src/config_save.c \
	src/textures.c \
	src/player.c \
	src/screen.c \
	src/render.c \
	src/raycast.c \
	src/movements.c

BONUS = bonus/main_bonus.c \
	src/game_utils.c \
	src/game_hooks.c \
	src/map.c \
	src/map_utils.c \
	src/map_check.c \
	src/map_read.c \
	src/map_closed.c \
	src/config.c \
	src/config_utils.c \
	src/config_color.c \
	src/config_save.c \
	src/textures.c \
	src/player.c \
	src/screen.c \
	src/render.c \
	src/raycast.c \
	src/movements.c \
	bonus/minimap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
LIBFT = lib/libft/libft.a
MLX_DIR = lib/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MAC_MLX_DIR = lib/minilibx_opengl
MAC_MLX_LIB = $(MAC_MLX_DIR)/libmlx.a
MAC_MLX_FLAGS = -L$(MAC_MLX_DIR) -lmlx -framework OpenGL -framework AppKit

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
	$(CC) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

mac:
	rm -f $(OBJS) $(BONUS_OBJS) $(NAME) $(BONUS_NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C $(MAC_MLX_DIR) clean
	$(MAKE) MLX_DIR=$(MAC_MLX_DIR) MLX_LIB=$(MAC_MLX_LIB) \
		MLX_FLAGS="$(MAC_MLX_FLAGS)" $(NAME)
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C lib/libft clean

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C lib/libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C lib/libft fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus mac
