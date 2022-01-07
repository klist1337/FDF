# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 13:46:23 by eassofi           #+#    #+#              #
#    Updated: 2022/01/07 12:29:25 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/ft_atoi.c src/ft_putchar.c src/ft_putstr.c \
		src/ft_strlcpy.c src/get_next_line_utils.c src/fdf.c \
		src/ft_draw.c src/ft_putnbr_int.c src/ft_split.c \
		src/get_next_line.c src/read_file.c src/menu.c src/set_data.c\
		src/isometric.c src/change_win_size.c src/handle_key.c
CC = cc 
INC = /usr/local/include
LIB = /usr/local/lib
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -lmlx -framework Opengl -framework Appkit
EXEC = fdf
RM = rm -rf
FSAN = -fsanitize=address

all: $(EXEC) 

$(EXEC): 
	@echo "\033[1;32mFDF IS READY!"
		$(CC) $(CFLAGS) -I $(INC) -L $(LIB) $(LIBFLAGS) $(SRC) -o $@

clean:   
	@echo "\033[1;34mCLEANER"
		$(RM) $(EXEC)
	

fclean: clean
	@echo "\033[1;33mFCLEANER"

re: fclean all
	@echo "\033[1;35mRecompiler"
