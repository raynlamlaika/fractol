NAME = fractol

SRCB = draw_julia_bonus.c fractol_bonus.c ft_atof_bonus.c init_fractal_bonus.c julia_bonus.c \
       malbor_bonus.c utils_bonus.c

SRC = mandatory/fractol.c mandatory/init_fractal.c mandatory/malbor.c \
      mandatory/utils.c mandatory/julia.c mandatory/ft_atof.c mandatory/draw_julia.c 

CC = cc
CFLAGS =  -Lmlx -lmlx -lXext -lX11  #-Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

HEADERB = fractol_bonus.h
HEADER = mandatory/fractol.h

all: $(NAME)

bonus: $(OBJB)
	$(CC) $(OBJB) -Lmlx -lmlx -lXext -lX11 -o $(NAME) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -lXext -lX11 -o $(NAME) -o $(NAME)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@



%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJB) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


CFLAGS =  -Lmlx -lmlx -lXext -lX11  #-Wall -Werror -Wextra
#for mac 
# NAME = fractol

# SRC = fractol.c init_fractal.c malbor.c utils.c julia.c ft_atof.c draw_julia.c

# OBJ = $(SRC:.c=.o)
# BOBJ = $(BSRC:.c=.o)

# CC = cc
# CFLAGS =  -lmlx -framework OpenGL -framework AppKit #-Wall -Werror -Wextra

# HEADER = fractol.h

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $^ $(CFLAGS)  -o $(NAME)

# # bonus: $(BOBJ)
# # 	$(CC) $(CFLAGS) $^ -o $(NAME)

# %.o: %.c $(HEADER)
# 	$(CC) -Imlx -c $< -o $@

# # bonus/%.o: bonus/%.c $(HEADERB)
# # 	$(CC) $(CFLAGS) -Ibonus -c $< -o $@

# clean:
# 	rm -f $(OBJ) $(BOBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all