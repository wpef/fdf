all:
	gcc -Wall -Werror -Wextra -o fdf src/*.c -Iinc/ -Llibft -lft mlx/libmlx.a

val:
	gcc -g -Wall -Werror -Wextra -o fdf src/*.c -Iinc/ -Llibft -lft mlx/libmlx.a
