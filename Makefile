# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 14:45:40 by mkivipur          #+#    #+#              #
#    Updated: 2020/01/14 14:30:31 by mkivipur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./fillitfiles/make_tetri.c ./fillitfiles/read.c ./fillitfiles/solve.c ./fillitfiles/make_map.c ./fillitfiles/solve_support.c ./fillitfiles/stock_tetri.c ./fillitfiles/validate.c ./fillitfiles/main.c ./fillitfiles/validate2.c
OBJS = ./fillitfiles/*.o

HDR = ./fillitfiles/ 

LIBFT = libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a
clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all
