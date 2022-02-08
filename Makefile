NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =  bresenham.c get_map_data.c get_next_line.c get_next_line_utils.c points.c utils.c rotation.c
SRC_MAN = fdf.c draw.c keys.c
SRC_BONUS = fdf_bonus.c draw_bonus.c keys_bonus.c

OBJ=$(SRC:.c=.o)
OBJ_MAN=$(SRC_MAN:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
EXT_LIB = libmacft.a
LINK_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAN)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_MAN) $(LINK_FLAGS) $(EXT_LIB) -o $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_BONUS) $(LINK_FLAGS) $(EXT_LIB) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all