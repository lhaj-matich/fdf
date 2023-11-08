NAME = fdf

HEADER = fdf.h

SRC = srcs/fdf.c srcs/draw.c srcs/keys.c srcs/bresenham.c srcs/get_map_data.c srcs/get_next_line.c srcs/get_next_line_utils.c \
srcs/points.c srcs/utils.c srcs/rotation.c srcs/libft.c
OBJ=$(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
LINK_FLAGS =  -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LINK_FLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
