NAME = fractol
NAMEB = fractol_bonus


SRCB = draw_julia_bonus.c fractol_bonus.c ft_atof_bonus.c init_fractal_bonus.c julia_bonus.c \
       malbor_bonus.c utils_bonus.c buring_ship_bonus.c burning_helper.c clear_bonus.c

SRC = mandatory/fractol.c mandatory/init_fractal.c mandatory/malbor.c \
      mandatory/utils.c mandatory/julia.c mandatory/ft_atof.c mandatory/draw_julia.c  mandatory/clear.c

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS =  -lmlx -framework OpenGL  -framework AppKit

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

HEADERB = fractol_bonus.h
HEADER = mandatory/fractol.h

all: $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(OBJB) $(HEADERB)
	$(CC) $(OBJB) $(MLX_FLAGS) -o $(NAMEB)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJB) $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)_bonus

re: fclean all
