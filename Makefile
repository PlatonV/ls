# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplaton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/20 09:52:38 by vplaton           #+#    #+#              #
#    Updated: 2015/11/20 12:07:12 by vplaton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = gcc
NAME = ft_ls
FLAGS = -Wall -Werror -Wextra
SRC = ft_ls.c\
	  list.c\
	  lsdata_list.c\
	  flags.c
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
