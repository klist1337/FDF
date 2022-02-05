# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 13:46:23 by eassofi           #+#    #+#              #
#    Updated: 2022/02/04 04:17:24 by eassofi          ###   ########.fr        #
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
NAME = fdf
RM = rm -rf

$(NAME):
	@echo "\033[1;32mFDF IS READY!"
		@$(CC) -I $(INC) -L $(LIB) $(LIBFLAGS) $(SRC) -o $@

all: $(NAME) 

clean:   
	@echo "\033[1;34mFDF IS DELETED!"
		@$(RM) $(NAME)
	
fclean: clean
	
re: fclean all