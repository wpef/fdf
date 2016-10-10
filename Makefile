# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/19 13:46:47 by fde-monc          #+#    #+#              #
#    Updated: 2016/10/10 19:58:10 by fde-monc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = -Lmlx/ -lmlx -framework OpenGL -framework AppKit

PATH_SRC = src/

SRC =	check_file.c \
		debug.c \
		error.c \
		get_infos.c \
		main.c \
		maketab.c \
		print_line.c \
		run.c

SRC_FILE = $(addprefix $(PATH_SRC), $(SRC));

OBJECTS = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

LIB = libft

LIB_EXE = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIB_EXE)
	 $(CC) $(LIBS) $(CFLAGS) -Iinc/ -L$(LIB) -lft $(OBJECTS) -o $(NAME)

$(LIB_EXE) :
	make -C $(LIB) nclean

$(OBJECTS) : %.o : %.c
	$(CC) $(CFLAGS) -Iinc/ -c $< -o $@

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)

nclean : all clean
