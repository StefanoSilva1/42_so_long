NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(LIBFT_DIR) -I $(MLX_DIR)

LIBFT_DIR = ./libft
OBJ_DIR = ./obj
MLX_DIR = ./minilibx-linux

SRCS = 	src/flood_fill.c\
		src/get_next_line.c\
		src/main.c\
		src/move_character.c\
		src/read_map.c\
		src/rendering.c\
		src/valid_arg.c\
		src/validate_map.c\
		src/window.c\

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
