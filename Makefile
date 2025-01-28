NAME        = so_long
NAME_BONUS  = so_long_bonus

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -I $(LIBFT_DIR) -I $(MLX_DIR)

LIBFT_DIR   = ./libft
OBJ_DIR     = ./obj
MLX_DIR     = ./minilibx-linux

SRCS        = src/flood_fill.c\
              src/get_next_line.c\
              src/main.c\
              src/move_character.c\
              src/read_map.c\
              src/rendering.c\
              src/valid_arg.c\
              src/validate_map.c\
              src/window.c\

SRCS_BONUS  = src_bonus/flood_fill_bonus.c\
              src_bonus/get_next_line_bonus.c\
              src_bonus/main_bonus.c\
              src_bonus/move_character_bonus.c\
              src_bonus/move_character2_bonus.c\
              src_bonus/read_map_bonus.c\
              src_bonus/rendering_bonus.c\
              src_bonus/valid_arg_bonus.c\
              src_bonus/validate_map_bonus.c\
              src_bonus/window_bonus.c\

OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX_LIB     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(OBJS_BONUS) $(LIBFT) $(MLX_LIB) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
