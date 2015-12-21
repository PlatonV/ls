# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplaton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/20 09:52:38 by vplaton           #+#    #+#              #
#*   Updated: 2015/12/19 12:06:42 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CXX = gcc
NAME = ft_ls
FLAGS = -Wall -Werror -Wextra
SRC = main.c\
	  ft_ls.c\
	  list.c\
	  lsdata_list.c\
	  lsdata_list_2.c\
	  long.c\
	  long_2.c\
	  flags.c\
	  error.c\
	  utils.c
OBJ = *.o
HEADERS = libft/
LIBS = libft/ -lft

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	$(CXX) $(FLAGS) -I $(HEADERS) -c $(SRC)
	$(CXX) $(FLAGS) -I $(HEADERS) -c $(SRC)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
