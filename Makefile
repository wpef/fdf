all:
	gcc -Wall -Werror -Wextra -o fdf src/*.c -Iinc/ -Llibft -lft
