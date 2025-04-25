NAME = so_long

cc = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = include
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

all: $(NAME)
$(NAME): $(OBJ) $(LIBFT) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re