NAME = fractol

SRC = fractol.c init_fractal.c malbor.c utils.c julia.c ft_atof.c draw_julia.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS =  -lmlx -framework OpenGL -framework AppKit #-Wall -Werror -Wextra

HEADER = fractol.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(CFLAGS)  -o $(NAME)

# bonus: $(BOBJ)
# 	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -Imlx -c $< -o $@

# bonus/%.o: bonus/%.c $(HEADERB)
# 	$(CC) $(CFLAGS) -Ibonus -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all