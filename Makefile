all:
	gcc -Wall -Werror -Wextra -o fdf src/*.c -Iinc/ -Llibft -lft

val:
	gcc -g -Wall -Werror -Wextra -o fdf src/*.c -Iinc/ -Llibft -lft
