NAME = push_swap

FLAGS = -Werror -Wextra -Wall
LIBS = -L ./libft -lft

FILES = main.c \
	test_sets.c \

OBJ_FILES = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) -I ./test_sets.h -c $(FILES)
	gcc $(FLAGS) -I ./test_sets.h -o $(NAME) $(OBJ_FILES) $(LIBS)

dev:
	gcc $(FLAGS) -I ./test_sets.h -c $(FILES)
	gcc $(FLAGS) -I ./test_sets.h -o $(NAME) $(OBJ_FILES) $(LIBS)

clean:
	make -C ./libft clean
	rm -f $(OBJ_FILES)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
