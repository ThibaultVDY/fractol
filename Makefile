NAME 		= fractol

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror -O3
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= mlx_linux
LIBMLX 		= $(MLX)/mlx.h

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		=
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)
	$(MAKE) -C $(MLX)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)


$(MLX):
	$(CLONE) https://github.com/42Paris/minilibx-linux.git $(MLX)

$(FT):
	$(CLONE) https://github.com/kodokaii/libft_full.git $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if [ -d "$(MLX)" ]; then $(MAKE) clean -C $(MLX); fi
	if [ -d "$(FT)" ]; then $(MAKE) clean -C $(FT); fi
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX)
	$(RM) -r $(FT)

re: fclean all

.PHONY:		all bonus clear clean fclean re
