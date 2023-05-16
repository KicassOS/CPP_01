# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 16:09:59 by pszleper          #+#    #+#              #
#    Updated: 2023/05/16 14:16:52 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILATION = c++ -Wall -Wextra -Werror -std=c++98

SRC = main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = Zombie.hpp

NAME = ./Zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILATION) $^ -o $(NAME)

%.o: %.cpp
	$(COMPILATION) $^ -c -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all